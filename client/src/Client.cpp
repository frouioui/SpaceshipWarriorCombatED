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

    std::cout << "now about to run" << std::endl;
    while (_running) {

    }
    return 0;
}