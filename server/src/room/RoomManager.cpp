#include <iostream>
#include "room/RoomManager.hpp"

RoomManager::RoomManager() : _rooms(0)
{
    boost::asio::io_context io_context;
    std::vector<UDPInfo> info = {{io_context, 30000}, {io_context, 30001}, {io_context, 30002}, {io_context, 30004}} ;
    _rooms.push_back(std::make_shared<Room>(info[0], 1));
    _rooms.push_back(std::make_shared<Room>(info[1], 2));
    _rooms.push_back(std::make_shared<Room>(info[2], 3));
    _rooms.push_back(std::make_shared<Room>(info[3], 4));
    std::thread([&](){_rooms[0]->run();}).detach();
    std::thread([&](){_rooms[1]->run();}).detach();
    std::thread([&](){_rooms[2]->run();}).detach();
    std::thread([&](){_rooms[3]->run();}).detach();
}

RoomManager::~RoomManager()
{
}

UDPInfo RoomManager::getNewUDPInfoForRoom()
{
    boost::asio::io_context io_context;
    UDPInfo info = {io_context, 10001};
    return info;
}

unsigned short RoomManager::getAvailablePort()
{
    unsigned short port = 0;
    for (size_t i = 0; i < _LIMIT_ROOM; i++) {
        std::cout << _AVAILABLE_PORTS[i].used << std::endl;
        if (_AVAILABLE_PORTS[i].used == false) {
            port = _AVAILABLE_PORTS[i].port;
            _AVAILABLE_PORTS[i].used = true;
            std::cout << "PORT=" << port << std::endl;
            return port;
        }
    }
    return port;
}

std::vector<std::shared_ptr<Room>> RoomManager::getAllRoom()
{
    return _rooms;
}

std::shared_ptr<Room> RoomManager::getRoomById(unsigned short id)
{
    for (auto &&i : _rooms) {
        if (i->getRoomId() == id) {
            return i;
        }
    }
    return  nullptr;
}

unsigned short RoomManager::getNewId() const
{
    bool done = false;
    bool current = false;
    unsigned short id = 0;

    while (done == false) {
        id = std::rand() % 9999;
        current = false;
        for (size_t i = 0; i < _rooms.size() && current == false; i++) {
            if (_rooms[i]->getRoomId() == id)
                current = true;
        }
        if (current == false)
            done = true;
    }
    return id;
}