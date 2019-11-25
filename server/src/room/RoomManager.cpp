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

void RoomManager::addAndRunRoom(Client &client)
{
    boost::asio::io_context io_context;
    UDPInfo info = {io_context, 101};

    unsigned short new_id = getNewId();
    _rooms.emplace_back(info, new_id);
    getRoomById(new_id).addClient(client);

    // run
    std::thread([&](){getRoomById(new_id).run();}).detach();
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