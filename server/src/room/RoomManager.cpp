#include <iostream>
#include "room/RoomManager.hpp"

RoomManager::RoomManager()
{
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
            return port;
        }
    }
    return port;
}

bool RoomManager::addAndRunRoom(Client &client)
{
    if (_rooms.size() == _LIMIT_ROOM) {
        return false;
    }

    const unsigned short port = getAvailablePort();
    boost::asio::io_context io_context;
    UDPInfo info = {io_context, static_cast<short>(port)};
    unsigned short new_id = getNewId();
    _rooms.emplace_back(info, new_id);
    getRoomById(new_id).addClient(client);

    // run
    std::thread([&](){getRoomById(new_id).run();}).detach();
    return true;
}

std::vector<Room> &RoomManager::getAllRoom()
{
    return _rooms;
}

Room &RoomManager::getRoomById(unsigned short id)
{
    for (auto &&i : _rooms) {
        if (i.getRoomId() == id) {
            return i;
        }
    }
    return _rooms[0];
}

unsigned short RoomManager::getNewId() const
{
    bool done = false;
    bool current = false;
    unsigned short id = 0;

    while (done == false) {
        id = rand() % 9999;
        current = false;
        for (size_t i = 0; i < _rooms.size() && current == false; i++) {
            if (_rooms[i].getRoomId() == id)
                current = true;
        }
        if (current == false)
            done = true;
    }
    return id;
}