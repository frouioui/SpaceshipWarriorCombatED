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

	packet.setAction(PRTL::Actions::AUTH);
	packet.setResponse(PRTL::Responses::SUCCESS);
	packet.setToken(_client_manager.generateToken());
	packet.set(received_packet.getIp());
	packet.set(received_packet.getPort());
	client.setIp(received_packet.getIp());
	client.setPort(received_packet.getPort());
	client.setUsername(received_packet.getData(PRTL::USER));
	_client_manager.addClient(client);
	respondToClient(packet);
}