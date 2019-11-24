#include <iostream>
#include <thread>

#include "Protocol.hpp"
#include "network/NetworkManager.hpp"

NetworkManager::NetworkManager(UDPInfo &info) : _udp(info)
{
    _connected = false;
    _running = false;
}

NetworkManager::NetworkManager(UDPInfo &info, const std::string &server_ip, short server_port) : _udp(info), _config(server_ip, server_port)
{
    _connected = false;
    _running = false;
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
    _running = true;
    std::thread([&](){authToServer();}).detach();
    std::thread([&](){receive();}).detach();
}

void NetworkManager::authToServer()
{
    std::cout << "starting authentification" << std::endl;
    while (_connected == false) {
        _mutex.lock();
        Packet packet(_config.getServerIp(), _config.getServerPort());
        packet.setAction(PRTL::Actions::AUTH);
        packet.setData(PRTL::USER, "rtype");
        packet.setData(PRTL::PASSWORD, "rtype");
        _udp.send(packet);
        _mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    std::cout << "authentification is done" << std::endl;
}

void NetworkManager::receive()
{
    while (true) {
        Packet packet = _udp.receive();

        if (packet.getAction() == PRTL::Actions::AUTH && packet.getResponse() == PRTL::Responses::SUCCESS) {
            _auth_token = packet.getData("token");
            _connected = true;
            std::cout << "logged in with token: " << _auth_token << std::endl;
        } else if (packet.getAction() == PRTL::Actions::AUTH && packet.getResponse() == PRTL::Responses::FAILURE) {
            std::cout << "server denied auth" << std::endl;
        } else if (_connected == false) {
            std::cout << "not logged in" << std::endl;
        } else {
            _mutex.lock();
            _queue_received.emplace_back(packet);
            _mutex.unlock();
        }
    }
}