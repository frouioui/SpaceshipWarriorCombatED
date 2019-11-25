#if !defined(ROOM_MANAGER_HPP)
#define ROOM_MANAGER_HPP

#include <vector>
#include <mutex>

#include "room/Room.hpp"

class RoomManager
{
public:
    RoomManager();
    ~RoomManager();

    void addAndRunRoom(Room &room, Client &client);
    std::vector<Room> &getAllRoom();
    Room &getRoomById(unsigned short id);
    UDPInfo getNewUDPInfoForRoom();

private:
    std::vector<Room> _rooms;

    unsigned short getNewId() const;
};




#endif // ROOM_MANAGER_HPP
