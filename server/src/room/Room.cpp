#include <exception>
#include <iostream>
#include "room/Room.hpp"

Room::Room(UDPInfo &info) : _udp_server(info)
{
    _running = false;
}

Room::Room(Room &source) : _udp_server(source._udp_server)
{
    _running = source.isRunning();
    _room_id = source._room_id;
}

Room::Room(Room &&source) : _udp_server(source._udp_server)
{
    _running = source.isRunning();
    _room_id = source._room_id;
}

Room::Room(UDPInfo info, unsigned short room_id) : _udp_server(info)
{
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

void Room::run() throw()
{
    _mutex.lock();
    _running = true;
    _mutex.unlock();
    Packet packet;
    while (_running == true) {
        try {
            packet = _udp_server.receive();
            std::thread([&](){this->managePacket(packet);}).detach();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void Room::managePacket(Packet packet)
{
	switch (packet.getAction())
	{
	case PRTL::Actions::AUTH:		
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
