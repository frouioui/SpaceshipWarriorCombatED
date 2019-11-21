#ifndef NETWORKMANAGER_HPP
#define NETWORKMANAGER_HPP

#include "UDP.hpp"

class NetworkManager {
public:
	NetworkManager(UDPInfo &info) : _udp(info) {_port = info.port;}
	~NetworkManager();

    void init(); // init queue and all
	int run();

protected:

private:
	UDP _udp; // UDP - Network communication
	short _port; // NetworkManager's network port

    // add main loop
};

#endif /* !NETWORKMANAGER_HPP */
