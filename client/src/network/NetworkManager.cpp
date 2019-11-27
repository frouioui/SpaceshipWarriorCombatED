#include <iostream>
#include <thread>

#include "Protocol.hpp"
#include "network/NetworkManager.hpp"
#include "event.hpp"

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
    std::thread([&](){handleRecieve();}).detach();
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
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
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

void NetworkManager::handleRecieve()
{
    while (true) {
        auto it = _queue_received.cbegin();
        while (it != _queue_received.cend()) {
            if (it->getAction() == PRTL::Actions::JOIN_ROOM) {
                if (it->getResponse() == PRTL::Responses::SUCCESS) {
                    std::cout << "joined room" << std::endl;
                }
        
            } else if (it->getAction() == PRTL::Actions::GET_ROOMS) {
                dataPacket data = it->getData();
                std::cout << "Number of rooms: " << data[PRTL::NB_ROOM] << std::endl;
        
            } else if (it->getAction() == PRTL::Actions::NEWCO) {
                if (it->getResponse() == PRTL::Responses::SUCCESS) {
                    _config.setGameServerIp(it->getIp());
                    _config.setGameServerPort(it->getPort());
                }

            } else if (it->getAction() == PRTL::Actions::INFO_ROOM) {  
                dataPacket data = it->getData();
                std::string username = data[PRTL::USER];
                Player player;
                player.setUsername(username);
                _players.push_back(player);

            } else if (it->getAction() == PRTL::Actions::CREATE_ROOM) {
                if (it->getResponse() == PRTL::Responses::FAILURE) {
                    std::cout << "Error when creating the room" << std::endl;
                }

            } else if (it->getAction() == PRTL::Actions::BOUNDINGBOX) {
                _mutex.lock();
                _bounding_boxes.push_back(*(it));
                _mutex.unlock();
            }

            _mutex.lock();
            it = _queue_received.erase(_queue_received.begin());
            if (it != _queue_received.cend())
                it = std::next(it);
            _mutex.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    } 
}

std::vector<Packet> NetworkManager::transfertQueueBoundingBoxes()
{
    _mutex.lock();
    std::vector<Packet> bdboxes = _bounding_boxes;
    _bounding_boxes.erase(_bounding_boxes.cbegin(), _bounding_boxes.cend());
    _mutex.unlock();
    return bdboxes;
}

void NetworkManager::getAvailableRooms()
{
    Packet packet(_config.getServerIp(), _config.getServerPort());
    packet.setToken(_auth_token);
    packet.setAction(PRTL::Actions::GET_ROOMS);
    _mutex.lock();
    _udp.send(packet);
    _mutex.unlock();
}

void NetworkManager::createAndJoinRoom()
{
    Packet packet(_config.getServerIp(), _config.getServerPort());
    packet.setToken(_auth_token);
    packet.setAction(PRTL::Actions::CREATE_ROOM);
    _mutex.lock();
    _udp.send(packet);
    _mutex.unlock();
}

void NetworkManager::joinRoom(unsigned short id_room)
{
    Packet packet(_config.getServerIp(), _config.getServerPort());
    packet.setToken(_auth_token);
    packet.setAction(PRTL::Actions::JOIN_ROOM);
    packet.setData(PRTL::ID_ROOM, std::to_string(id_room));
    _mutex.lock();
    _udp.send(packet);
    _mutex.unlock();
}

void NetworkManager::sendInput(input input)
{
    Packet packet(_config.getGameServerIp(), _config.getGameServerPort());
    packet.setToken(_auth_token);
    packet.setAction(PRTL::Actions::INPUT);
    packet.setData(PRTL::INPUT, std::to_string(input));
    _mutex.lock();
    _udp.send(packet);
    _mutex.unlock();
}