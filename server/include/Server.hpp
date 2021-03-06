#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <mutex>

#include "UDP.hpp"
#include "client/ClientManager.hpp"
#include "room/RoomManager.hpp"

class Server
{
public:
	Server(UDPInfo &info);
	~Server();

	int run() throw();

private:
	UDP _udp_server;
	ClientManager _client_manager;
	RoomManager _room_manager;

	bool _running;

	std::mutex _mutex;

	void managePacket(Packet packet);
	void respondToClient(Packet packet);
	void authClient(Packet packet);
	void getRooms(Packet packet);
	void joinRoom(Packet packet);
};

#endif /* !SERVER_HPP_ */
