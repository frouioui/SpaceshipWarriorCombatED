#if !defined(ROOM_HPP)
#define ROOM_HPP

#include <mutex>
#include <chrono>
#include <ctime>

#include "UDP.hpp"
#include "Basic.hpp"
#include "Packet.hpp"
#include "client/ClientManager.hpp"
#include "Rtype.hpp"


class Room
{
public:
    Room(UDPInfo &info);
    Room(Room &source);
    Room(Room &&source);
    Room(UDPInfo info, unsigned short room_id);

    ~Room();

    void setRoomId(unsigned short room_id);

    unsigned short getRoomId() const;

    void run() throw();
    void stop();
    bool isRunning() const;

    void sendServerInfo(unsigned short player_id);

    void managePacket(Packet packet);

    void addClient(Client client);

    void finishUDP();

private:
    ClientManager _client_manager; // All the client in the current room

    UDP _udp_server;

    std::unique_ptr<IGame> _game;

    bool _running;

    std::mutex _mutex;

    unsigned short _room_id;

    std::chrono::time_point<std::chrono::system_clock> _clock;

    void sendInfoToClient();
    void sendInfoBoundingBoxes();
    void waitForReady();
};


#endif // ROOM_HPP
