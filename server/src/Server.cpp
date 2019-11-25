#include <exception>
#include <iostream>
#include "Server.hpp"
#include "client/Client.hpp"

Server::Server(UDPInfo &info) : _udp_server(info)
{
	_running = false;
}

Server::~Server()
{
}

int Server::run() throw()
{
	_running = true;

	Packet packet;
	while (_running) {
		try {
			packet = _udp_server.receive();
			managePacket(packet);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

void Server::managePacket(Packet packet)
{
	switch (packet.getAction())
	{
	case PRTL::Actions::AUTH:
		authClient(packet);
		break;

	case PRTL::Actions::GET_ROOMS:
		getRooms(packet);
		break;

	case PRTL::Actions::JOIN_ROOM:
		joinRoom(packet);
		break;

	case PRTL::Actions::CREATE_ROOM:
		createRoom(packet);
		break;

	default:
		break;
	}
}

void Server::respondToClient(Packet packet)
{
	_udp_server.send(packet);
}

void Server::authClient(Packet received_packet)
{
	// we can check user name and password here

	Packet packet;
	Client client;

	std::string token = _client_manager.generateToken();

	packet.setAction(PRTL::Actions::AUTH);
	packet.setResponse(PRTL::Responses::SUCCESS);
	packet.setToken(token);
	packet.set(received_packet.getIp());
	packet.set(received_packet.getPort());
	client.setIp(received_packet.getIp());
	client.setPort(received_packet.getPort());
	client.setUsername(received_packet.getData(PRTL::USER));
	client.setToken(token);
	_client_manager.addClient(client);
	respondToClient(packet);
}

void Server::getRooms(Packet received_packet)
{
	std::string token_client = received_packet.getToken();

	if (token_client.empty()) {
		std::cout << "token is empty" << std::endl;
		return;
	}
	Client client = _client_manager.getClientByToken(token_client);
	if (client.getToken() != token_client) {
		std::cout << "no token found" << std::endl;
		return;
	}

	Packet packet;
	std::vector<Room> &rooms = _room_manager.getAllRoom();
	unsigned int nb_rooms = rooms.size();

	packet.setAction(PRTL::Actions::GET_ROOMS);
	packet.set(received_packet.getIp());
	packet.set(received_packet.getPort());
	packet.setData(PRTL::NB_ROOM, std::to_string(nb_rooms));
	for (size_t i = 0; i < nb_rooms; i++) {
		std::string room_name = PRTL::ID_ROOM + std::to_string(i);
		packet.setData(room_name, std::to_string(rooms[i].getRoomId()));
	}
	respondToClient(packet);
}

void Server::createRoom(Packet received_packet)
{
	std::string token_client = received_packet.getToken();

	if (token_client.empty()) {
		std::cout << "token is empty" << std::endl;
		return;
	}
	Client client = _client_manager.getClientByToken(token_client);
	if (client.getToken() != token_client) {
		std::cout << "no token found" << std::endl;
		return;
	}
	_room_manager.addAndRunRoom(client);
	// The client is now in the new room
	// and the room is up and running.
}

void Server::joinRoom(Packet received_packet)
{
	std::string token_client = received_packet.getToken();

	if (token_client.empty()) {
		std::cout << "token is empty" << std::endl;
		return;
	}
	Client client = _client_manager.getClientByToken(token_client);
	if (client.getToken() != token_client) {
		std::cout << "no token found" << std::endl;
		return;
	}

	dataPacket data = received_packet.getData();
	unsigned short requested_room_id = static_cast<unsigned short>(std::atoi(data[PRTL::ID_ROOM].c_str()));
	
	_room_manager.getRoomById(requested_room_id).addClient(client);
}