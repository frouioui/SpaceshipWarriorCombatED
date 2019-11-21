#include "network/NetworkManager.hpp"
#include <iostream>

NetworkManager::~NetworkManager()
{
}

void NetworkManager::init()
{
    std::cout << "toto" << std::endl;
    _udp.send("salut", "127.0.0.1", 99);
}

int NetworkManager::run()
{
    return 0;
}