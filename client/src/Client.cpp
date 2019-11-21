#include <iostream>
#include "Client.hpp"

Client::Client(UDPInfo &info) : _network(info)
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