#if !defined(PACKET_HPP)
#define PACKET_HPP

#include <string>

#include "Basic.hpp"
#include "Protocol.hpp"

class Packet
{
public:
    Packet();
    Packet(dataPacket &data);
    Packet(short port, dataPacket &data);
    Packet(const std::string &ip, dataPacket &data);
    Packet(const std::string &ip, short port);
    Packet(const std::string &ip, short port, dataPacket &data);

    ~Packet();

    void setData(const std::string &key, const std::string &value);
    void setAction(PRTL::Actions action);
    void setResponse(PRTL::Responses resp);
    void setToken(const std::string &token);
    void set(dataPacket &data);
    void set(const std::string &ip);
    void set(short port);

    dataPacket getData() const;
    PRTL::Actions getAction() const;
    PRTL::Responses getResponse() const;
    const std::string &getToken();
    const std::string &getData(const std::string &key);
    std::string getIp() const;
    short getPort() const;

    boost::asio::ip::address getIpAddress() const;

private:
    std::string _ip;
    short _port;
    dataPacket _data;
};

#endif // PACKET_HPP
