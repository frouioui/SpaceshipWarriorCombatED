#include <iostream>
#include "Client.hpp"

Client::Client(UDPInfo &info) : _network(info)
{
    _running = true;
}

Client::Client(UDPInfo &info, const std::string &server_ip, short server_port) : _network(info, server_ip, server_port)
{
    _running = true;
}


Client::~Client()
{
}

int Client::run() throw()
{
    _network.init();

    std::cout << "done with init" << std::endl;
    
    // wait until connected to server
    while (_network.isConnected() == false) {}

    // TEST
    // std::cout << "connected" << std::endl;
    // _network.createAndJoinRoom();
    // std::cout << "now about to run" << std::endl;
    // _network.getAvailableRooms();

    while (_running) {
    }
    return 0;
}