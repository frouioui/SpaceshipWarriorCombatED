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

    std::vector<std::shared_ptr<Room>> getAllRoom();
    std::shared_ptr<Room> getRoomById(unsigned short id);
    UDPInfo getNewUDPInfoForRoom();

private:
    const unsigned short _LIMIT_ROOM = 4;
    std::vector<Port> _AVAILABLE_PORTS = {{20000, false}, {20001, false}, {20002, false}, {20003, false}, {20004, false}};

    // unsigned short _port;

    std::vector<std::shared_ptr<Room>> _rooms;

    unsigned short getNewId() const;
    unsigned short getAvailablePort();
};




#endif // ROOM_MANAGER_HPP
