#include "Packet.hpp"

Packet::Packet()
{
    
}

Packet::Packet(dataPacket &data)
{
    _data = data;
}

Packet::Packet(short port, dataPacket &data)
{
    _port = port;
    _data = data;
}

Packet::Packet(const std::string &ip, dataPacket &data)
{
    _ip = ip;
    _data = data;
}

Packet::Packet(const std::string &ip, short port)
{
    _ip = ip;
    _port = port;
}

Packet::Packet(const std::string &ip, short port, dataPacket &data)
{
    _ip = ip;
    _port = port;
    _data = data;
}

Packet::~Packet()
{
}

void Packet::set(dataPacket &data)
{
    _data = data;
}

void Packet::set(const std::string &ip)
{
    _ip = ip;
}

void Packet::set(short port)
{
    _port = port;
}

dataPacket Packet::getData() const
{
    return _data;
}

std::string Packet::getIp() const
{
    return _ip;
}

short Packet::getPort() const
{
    return _port;
}

boost::asio::ip::address Packet::getIpAddress() const
{
    return boost::asio::ip::address::from_string(_ip);
}

const std::string &Packet::getData(const std::string &key)
{
    return _data[key];
}

void Packet::setData(const std::string &key, const std::string &value)
{
    _data[key] = value;
}