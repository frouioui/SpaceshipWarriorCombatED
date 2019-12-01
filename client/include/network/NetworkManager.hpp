#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include <mutex>

#include "NetworkConfig.hpp"
#include "UDP.hpp"
#include "Packet.hpp"
#include "network/player/Player.hpp"
#include "event.hpp"

class NetworkManager {
public:
	NetworkManager(UDPInfo &info);
	NetworkManager(UDPInfo &info, const std::string &server_ip, short server_port);
	
	~NetworkManager();

    void init(); // Init all the threads

	bool isConnected() const; // Tells wether or not the client is connected to the server
	void stop();

	void getAvailableRooms();
	void createAndJoinRoom();
	void joinRoom(unsigned short id_room);
	void readyToPlay();

	bool isInRoom() const;

	void sendInput(std::vector<input> input);

	std::vector<Packet> transfertQueueBoundingBoxes();
	std::vector<Packet> transfertQueueRenderings();
	void handleRecieve();

// attributes
private:
	UDP _udp; // UDP - Network communication
	NetworkConfig _config;

	bool _running;
	bool _connected; // Tells wether or not the client is connected to the server
	bool _in_room;
	std::string _auth_token; // The auth token sent by the server

	std::vector<Packet> _queue_send; // The queue of packet to send
	std::vector<Packet> _queue_received; // The queue of packet that have been received
	std::vector<Player> _players;

	std::vector<Packet> _bounding_boxes;
	std::vector<Packet> _renderings;

	std::mutex _mutex_send;
	std::mutex _mutex_receive;
	std::mutex _mutex_data;
	std::mutex _mutex_rendering;

	void authToServer(); // Loop that will authentificate the client to the server
	void receive();

};

#endif /* !NETWORKMANAGER_HPP */
