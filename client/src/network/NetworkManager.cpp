#include <iostream>
#include <thread>

#include "Protocol.hpp"
#include "network/NetworkManager.hpp"
#include "event.hpp"

NetworkManager::NetworkManager(UDPInfo &info) : _udp(info)
{
    _connected = false;
    _running = false;
    _in_room = false;
}

NetworkManager::NetworkManager(UDPInfo &info, const std::string &server_ip, short server_port) : _udp(info), _config(server_ip, server_port)
{
    _connected = false;
    _running = false;
    _in_room = false;
}

NetworkManager::~NetworkManager()
{
}

bool NetworkManager::isConnected() const
{
    return _connected;
}

bool NetworkManager::isInRoom() const
{
    return _in_room;
}

void NetworkManager::stop()
{
    Packet packet(_config.getServerIp(), _config.getServerPort());
    packet.setAction(PRTL::Actions::GOODBYE);
    packet.setToken(_auth_token);
    _mutex_send.lock();
    _udp.send(packet);
    _mutex_send.unlock();
    packet.set(_config.getGameServerIp());
    packet.set(_config.getGameServerPort());
    _mutex_send.lock();
    _udp.send(packet);
    _mutex_send.unlock();
    _running = false;
    std::cout << "HOEIRHFIOHRF" << std::endl;
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
    while (_connected == false && _running == true) {
        Packet packet(_config.getServerIp(), _config.getServerPort());
        packet.setAction(PRTL::Actions::AUTH);
        packet.setData(std::to_string(static_cast<int>(PRTL::Data::USER)), "rtype");
        packet.setData(std::to_string(static_cast<int>(PRTL::Data::PASSWORD)), "rtype");
        _mutex_send.lock();
        _udp.send(packet);
        _mutex_send.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void NetworkManager::receive()
{
    while (_running == true) {
        _mutex_receive.lock();
        Packet packet = _udp.receive();
        _mutex_receive.unlock();

        if (packet.getAction() == PRTL::Actions::AUTH && packet.getResponse() == PRTL::Responses::SUCCESS) {
            _auth_token = packet.getData(std::to_string(static_cast<int>(PRTL::Data::TOKEN)));
            _connected = true;
            std::cout << "logged in with token: " << _auth_token << std::endl;
        } else if (packet.getAction() == PRTL::Actions::AUTH && packet.getResponse() == PRTL::Responses::FAILURE) {
            std::cout << "server denied auth" << std::endl;
        } else if (_connected == false) {
            std::cout << "not logged in" << std::endl;
        } else {
            _mutex_data.lock();
            _queue_received.emplace_back(packet);
            _mutex_data.unlock();
            handleRecieve();
        }
    }
}

void NetworkManager::handleRecieve()
{
    if (_queue_received.size() > 0) {
        auto it = _queue_received.cbegin();
        while (it != _queue_received.cend()) {
            if (it->getAction() == PRTL::Actions::JOIN_ROOM) {
                if (it->getResponse() == PRTL::Responses::SUCCESS) {
                    std::cout << "joined room" << std::endl;
                }
        
            } else if (it->getAction() == PRTL::Actions::GET_ROOMS) {
                dataPacket data = it->getData();
                std::cout << "Number of rooms: " << data[std::to_string(static_cast<int>(PRTL::Data::NB_ROOM))] << std::endl;
        
            } else if (it->getAction() == PRTL::Actions::NEWCO) {
                if (it->getResponse() == PRTL::Responses::SUCCESS) {
                    _config.setGameServerIp(it->getIp());
                    _config.setGameServerPort(it->getPort());
                    _in_room = true;
                }

            } else if (it->getAction() == PRTL::Actions::INFO_ROOM) {  
                dataPacket data = it->getData();
                std::string username = data[std::to_string(static_cast<int>(PRTL::Data::USER))];
                Player player;
                player.setUsername(username);
                _players.push_back(player);

            } else if (it->getAction() == PRTL::Actions::CREATE_ROOM) {
                if (it->getResponse() == PRTL::Responses::FAILURE) {
                    std::cout << "Error when creating the room" << std::endl;
                }

            } else if (it->getAction() == PRTL::Actions::BOUNDINGBOX) {
                _mutex_data.lock();
                _bounding_boxes.push_back(*(it));
                _mutex_data.unlock();

            } else if (it->getAction() == PRTL::Actions::RENDERING) {
                _mutex_rendering.lock();
                _renderings.push_back(*(it));
                _mutex_rendering.unlock();
            }

            _mutex_data.lock();
            it = _queue_received.erase(_queue_received.begin());
            if (it != _queue_received.cend())
                it = std::next(it);
            _mutex_data.unlock();
        }
    }
}

std::vector<Packet> NetworkManager::transfertQueueBoundingBoxes()
{
    _mutex_data.lock();
    std::vector<Packet> bdboxes = _bounding_boxes;
    _bounding_boxes.erase(_bounding_boxes.cbegin(), _bounding_boxes.cend());
    _mutex_data.unlock();
    return bdboxes;
}

std::vector<Packet> NetworkManager::transfertQueueRenderings()
{
    _mutex_rendering.lock();
    std::vector<Packet> renderings = _renderings;
    _renderings.erase(_renderings.cbegin(), _renderings.cend());
    _mutex_rendering.unlock();
    return renderings;
}

void NetworkManager::getAvailableRooms()
{
    Packet packet(_config.getServerIp(), _config.getServerPort());
    packet.setToken(_auth_token);
    packet.setAction(PRTL::Actions::GET_ROOMS);
    _mutex_send.lock();
    _udp.send(packet);
    _mutex_send.unlock();
}

void NetworkManager::createAndJoinRoom()
{
    Packet packet(_config.getServerIp(), _config.getServerPort());
    packet.setToken(_auth_token);
    packet.setAction(PRTL::Actions::CREATE_ROOM);
    _mutex_send.lock();
    _udp.send(packet);
    _mutex_send.unlock();
}

void NetworkManager::joinRoom(unsigned short id_room)
{
    Packet packet(_config.getServerIp(), _config.getServerPort());
    packet.setToken(_auth_token);
    packet.setAction(PRTL::Actions::JOIN_ROOM);
    packet.setData(std::to_string(static_cast<int>(PRTL::Data::ID_ROOM)), std::to_string(id_room));
    _mutex_send.lock();
    _udp.send(packet);
    _mutex_send.unlock();
}

void NetworkManager::sendInput(std::vector<input> input)
{
    Packet packet(_config.getGameServerIp(), _config.getGameServerPort());
    packet.setToken(_auth_token);
    packet.setAction(PRTL::Actions::INPUT);
    if (input.size() == 0) {
        packet.setData(std::to_string(static_cast<int>(PRTL::Data::INPUT)), std::to_string(input::NOTHING));
        _mutex_send.lock();
        _udp.send(packet);
        _mutex_send.unlock();
    }
    for (auto& x : input) {
        packet.setData(std::to_string(static_cast<int>(PRTL::Data::INPUT)), std::to_string(x));
        _mutex_send.lock();
        _udp.send(packet);
        _mutex_send.unlock();
    }
}

void NetworkManager::readyToPlay()
{
    Packet packet(_config.getGameServerIp(), _config.getGameServerPort());
    packet.setToken(_auth_token);
    packet.setAction(PRTL::Actions::READY);
    _mutex_send.lock();
    _udp.send(packet);
    _mutex_send.unlock();
}