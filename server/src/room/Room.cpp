#include <exception>
#include <iostream>
#include "room/Room.hpp"

Room::Room(UDPInfo &info) : _udp_server(info), _game(std::make_unique<Rtype>())
{
    _running = false;
    _game->initGame(1, 0);
    _clock = std::chrono::system_clock::now();
}

Room::Room(Room &source) : _udp_server(source._udp_server), _game(std::make_unique<Rtype>())
{
    _running = source.isRunning();
    _room_id = source._room_id;
}

Room::Room(Room &&source) : _udp_server(source._udp_server), _game(std::make_unique<Rtype>())
{
    _running = source.isRunning();
    _room_id = source._room_id;
}

Room::Room(UDPInfo info, unsigned short room_id) : _udp_server(info), _game(std::make_unique<Rtype>())
{
    std::cout << "New room:" << room_id << std::endl;
    _room_id = room_id;
    _running = false;
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
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::CONTENT)), std::to_string(static_cast<int>(PRTL::Data::CIRCLE)));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::CIRCLE_POS_CENTER_X)), std::to_string(boundingBox.pos[circlePos::CENTER].second));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::CIRCLE_POS_CENTER_Y)), std::to_string(boundingBox.pos[circlePos::CENTER].first));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::CIRCLE_POS_RADIUS)), std::to_string(boundingBox.pos[circlePos::RADIUS].first));
        } else if (boundingBox.type == shapeType::SQUARE) {
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::CONTENT)), std::to_string(static_cast<int>(PRTL::Data::SQUARE)));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::SQUARE_UPPERLEFT_Y)), std::to_string(boundingBox.pos[squarePos::UPPERLEFT].first));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::SQUARE_UPPERLEFT_X)), std::to_string(boundingBox.pos[squarePos::UPPERLEFT].second));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::SQUARE_UPPERRIGHT_Y)), std::to_string(boundingBox.pos[squarePos::UPPERRIGHT].first));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::SQUARE_UPPERRIGHT_X)), std::to_string(boundingBox.pos[squarePos::UPPERRIGHT].second));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::SQUARE_LOWERLEFT_Y)), std::to_string(boundingBox.pos[squarePos::LOWERLEFT].first));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::SQUARE_LOWERLEFT_X)), std::to_string(boundingBox.pos[squarePos::LOWERLEFT].second));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::SQUARE_LOWERRIGHT_Y)), std::to_string(boundingBox.pos[squarePos::LOWERRIGHT].first));
            packetBoundingBox.setData(std::to_string(static_cast<int>(PRTL::Data::SQUARE_LOWERRIGHT_X)), std::to_string(boundingBox.pos[squarePos::LOWERRIGHT].second));
        }
        for (auto &&client : clients) {
            if (client.isConnected()) {
                packetBoundingBox.setAction(PRTL::Actions::BOUNDINGBOX);
                packetBoundingBox.set(client.getIp());
                packetBoundingBox.set(client.getPort());
                _udp_server.send(packetBoundingBox);
            }
        }  
    }
}

void Room::sendInfoToClient()
{
    while (true) {
        sendInfoBoundingBoxes();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/ 60));
    }
}

void Room::waitForReady()
{
    std::vector<Client> clients = _client_manager.getAllClients();
    Packet packet;

    while (_client_manager.isAllReady() == false) {
        packet = _udp_server.receive();
        if (packet.getAction() == PRTL::Actions::READY) {
            _client_manager.getClientByToken(packet.getToken()).ready();
        }
    }
}

void Room::run() throw()
{
    _running = true;
    Packet packet;

    while (_client_manager.getAllClients().size() == 0) {}
    std::cout << "ROOM [#" << _room_id << "] got its first client" << std::endl;

    waitForReady();
    _game->initGame(_client_manager.getAllClients().size(), 0);

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
        _game->addEvent({_client_manager.getClientByToken(packet.getToken()).getPlayerId() + 1, static_cast<input>(std::stoi(packet.getData(std::to_string(static_cast<int>(PRTL::Data::INPUT)))))});
		break;

    case PRTL::Actions::GOODBYE:
        _client_manager.disconnectClient(packet.getToken());
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
