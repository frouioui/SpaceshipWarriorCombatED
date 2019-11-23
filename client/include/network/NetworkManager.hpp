#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include <mutex>

#include "NetworkConfig.hpp"
#include "UDP.hpp"
#include "Packet.hpp"

class NetworkManager {
public:
	NetworkManager(UDPInfo &info);
	NetworkManager(UDPInfo &info, const std::string &server_ip, short server_port);
	
	~NetworkManager();

    void init(); // Init all the threads

	bool isConnected() const; // Tells wether or not the client is connected to the server

// attributes
private:
	UDP _udp; // UDP - Network communication
	NetworkConfig _config;

	bool _connected; // Tells wether or not the client is connected to the server

	std::vector<Packet> _queue_send; // The queue of packet to send
	std::vector<Packet> _queue_received; // The queue of packet that have been received

	std::mutex _mutex; // Main mutex of the network manager

	void authToServer(); // Loop that will authentificate the client to the server
};

#endif /* !NETWORKMANAGER_HPP */
