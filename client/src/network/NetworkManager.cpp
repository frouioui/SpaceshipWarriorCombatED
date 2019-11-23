#include <iostream>
#include <thread>

#include "Protocol.hpp"
#include "network/NetworkManager.hpp"

NetworkManager::NetworkManager(UDPInfo &info) : _udp(info)
{
    _connected = false;
}

NetworkManager::NetworkManager(UDPInfo &info, const std::string &server_ip, short server_port) : _udp(info), _config(server_ip, server_port)
{
    _connected = false;
}

NetworkManager::~NetworkManager()
{
}

bool NetworkManager::isConnected() const
{
    return _connected;
}

void NetworkManager::init()
{
    std::thread([&](){authToServer();}).detach();
}

void NetworkManager::authToServer()
{
    std::cout << "starting connection" << std::endl;
    while (_connected == false) {
        _mutex.lock();
        Packet packet;
        packet.set(_config.getServerPort());
        packet.set(_config.getServerIp());
        packet.setData(P_ACTION, P_ACTION_LOGIN);
        packet.setData(P_USER, "rtype");
        packet.setData(P_PASSWORD, "rtype");
        _udp.send(packet);
        _mutex.unlock();
    }
}