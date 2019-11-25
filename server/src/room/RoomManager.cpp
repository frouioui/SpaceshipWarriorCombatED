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
    UDPInfo info = {io_context, 0};
    return info;
}

void RoomManager::addAndRunRoom(Room &room, Client &client)
{
    room.setRoomId(getNewId());
    room.addClient(client);
    _rooms.emplace_back(room);

    // run
    std::thread([&](){getRoomById(room.getRoomId()).run();}).detach();
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