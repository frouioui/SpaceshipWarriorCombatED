#if !defined(ROOM_MANAGER_HPP)
#define ROOM_MANAGER_HPP

#include <vector>
#include <mutex>

#include "room/Room.hpp"

struct Port {
    unsigned short port;
    bool used;
};

class RoomManager
{
public:
    RoomManager();
    ~RoomManager();

    bool addAndRunRoom(Client &client);
    std::vector<Room> &getAllRoom();
    Room &getRoomById(unsigned short id);
    UDPInfo getNewUDPInfoForRoom();

private:
    const unsigned short _LIMIT_ROOM = 1;
    std::vector<Port> _AVAILABLE_PORTS = {{20000, false}};//, {20001, false}, {20002, false}, {20003, false}, {20004, false}};

    std::vector<Room> _rooms;

    unsigned short getNewId() const;
    unsigned short getAvailablePort();
};




#endif // ROOM_MANAGER_HPP
