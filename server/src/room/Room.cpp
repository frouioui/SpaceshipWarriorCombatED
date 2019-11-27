#include <exception>
#include <iostream>
#include "room/Room.hpp"

Room::Room(UDPInfo &info) : _udp_server(info), _game(std::make_unique<Rtype>())
{
    _running = false;
    _game->initGame(1, 0);
}

Room::Room(Room &source) : _udp_server(source._udp_server), _game(std::make_unique<Rtype>())
{
    _running = source.isRunning();
    _room_id = source._room_id;
    _game->initGame(1, 0);
}

Room::Room(Room &&source) : _udp_server(source._udp_server), _game(std::make_unique<Rtype>())
{
    _running = source.isRunning();
    _room_id = source._room_id;
    _game->initGame(1, 0);
}

Room::Room(UDPInfo info, unsigned short room_id) : _udp_server(info), _game(std::make_unique<Rtype>())
{
    _room_id = room_id;
    _running = false;
    _game->initGame(1, 0);
}

Room::~Room()
{
    _running = false;
}

void Room::finishUDP()
{
    _udp_server.finish();
    _running = false;
}

void Room::addClient(Client client)
{
    client.setPlayerId(_client_manager.generatePlayerId());
    _client_manager.addClient(client);
    sendServerInfo(client.getPlayerId());
}

void Room::sendServerInfo(unsigned short player_id)
{
    Packet packet;
    Client client = _client_manager.getClientByPlayerId(player_id);

    packet.setAction(PRTL::Actions::NEWCO);
    packet.setResponse(PRTL::Responses::SUCCESS);
    packet.set(client.getIp());
	packet.set(client.getPort());
    _udp_server.send(packet);
}

void Room::sendInfoBoundingBoxes()
{
    Packet packetBoundingBox;
    std::vector<boundingBox> boundingBoxes = _game->getBoundingBox();
    for (auto &&boundingBox : boundingBoxes) {
        std::vector<Client> clients = _client_manager.getAllClients();
        if (boundingBox.type == shapeType::CIRCLE) {
            packetBoundingBox.setData(PRTL::CONTENT, PRTL::CIRCLE);
            packetBoundingBox.setData(PRTL::CIRCLE_POS_CENTER_X, std::to_string(boundingBox.pos[circlePos::CENTER].second));
            packetBoundingBox.setData(PRTL::CIRCLE_POS_CENTER_Y, std::to_string(boundingBox.pos[circlePos::CENTER].first));
            packetBoundingBox.setData(PRTL::CIRCLE_POS_RADIUS, std::to_string(boundingBox.pos[circlePos::RADIUS].first));
        } else if (boundingBox.type == shapeType::SQUARE) {
            packetBoundingBox.setData(PRTL::CONTENT, PRTL::SQUARE);
            packetBoundingBox.setData(PRTL::SQUARE_UPPERLEFT_Y, std::to_string(boundingBox.pos[squarePos::UPPERLEFT].first));
            packetBoundingBox.setData(PRTL::SQUARE_UPPERLEFT_X, std::to_string(boundingBox.pos[squarePos::UPPERLEFT].second));
            packetBoundingBox.setData(PRTL::SQUARE_UPPERRIGHT_Y, std::to_string(boundingBox.pos[squarePos::UPPERRIGHT].first));
            packetBoundingBox.setData(PRTL::SQUARE_UPPERRIGHT_X, std::to_string(boundingBox.pos[squarePos::UPPERRIGHT].second));
            packetBoundingBox.setData(PRTL::SQUARE_LOWERLEFT_Y, std::to_string(boundingBox.pos[squarePos::LOWERLEFT].first));
            packetBoundingBox.setData(PRTL::SQUARE_LOWERLEFT_X, std::to_string(boundingBox.pos[squarePos::LOWERLEFT].second));
            packetBoundingBox.setData(PRTL::SQUARE_LOWERRIGHT_Y, std::to_string(boundingBox.pos[squarePos::LOWERRIGHT].first));
            packetBoundingBox.setData(PRTL::SQUARE_LOWERRIGHT_X, std::to_string(boundingBox.pos[squarePos::LOWERRIGHT].second));
        }
        for (auto &&client : clients) {
            packetBoundingBox.setAction(PRTL::Actions::BOUNDINGBOX);
            packetBoundingBox.set(client.getIp());
            packetBoundingBox.set(client.getPort());
            _udp_server.send(packetBoundingBox);
        }   
    }
}

void Room::sendInfoToClient()
{
    while (true) {
        sendInfoBoundingBoxes();
    }
}

void Room::run() throw()
{
    _mutex.lock();
    _running = true;
    _mutex.unlock();
    Packet packet;

    std::thread([&](){this->sendInfoToClient();}).detach();

    while (_running == true) {
        try {
            packet = _udp_server.receive();
            std::thread([&](){this->managePacket(packet);}).detach();
            _game->update();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void Room::managePacket(Packet packet)
{
	switch (packet.getAction())
	{
	case PRTL::Actions::INPUT:
        _game->addEvent({_client_manager.getClientByToken(packet.getToken()).getPlayerId(), static_cast<input>(std::stoi(packet.getData(PRTL::INPUT)))});
		break;

	default:
		break;
	}
}

void Room::stop()
{
    _running = false;
}

bool Room::isRunning() const
{
    return _running;
}

void Room::setRoomId(unsigned short room_id)
{
    _room_id = room_id;
}

unsigned short Room::getRoomId() const
{
    return _room_id;
}
