#include "Packet.hpp"

Packet::Packet() : _data(30)
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

void Packet::setAction(PRTL::Actions action)
{
    _data[std::to_string(static_cast<unsigned int>(PRTL::Data::ACTION))] = std::to_string(static_cast<unsigned int>(action));
}

PRTL::Actions Packet::getAction() const
{
    if (_data.find(std::to_string(static_cast<unsigned int>(PRTL::Data::ACTION))) != _data.end())
        return (static_cast<PRTL::Actions>(std::stoi(_data.at(std::to_string(static_cast<unsigned int>(PRTL::Data::ACTION))))));
    return (PRTL::Actions::UNKNOWN);
}

void Packet::setResponse(PRTL::Responses resp)
{
    _data[std::to_string(static_cast<unsigned int>(PRTL::Data::RESPONSE))] = std::to_string(static_cast<unsigned int>(resp));
}

PRTL::Responses Packet::getResponse() const
{
    if (_data.find(std::to_string(static_cast<unsigned int>(PRTL::Data::RESPONSE))) != _data.end())
        return (static_cast<PRTL::Responses>(std::stoi(_data.at(std::to_string(static_cast<unsigned int>(PRTL::Data::RESPONSE))))));
    return (PRTL::Responses::UNKNOWN);
}

void Packet::setToken(const std::string &token)
{
    _data[std::to_string(static_cast<unsigned int>(PRTL::Data::TOKEN))] = token;
}

const std::string &Packet::getToken()
{
    return _data[std::to_string(static_cast<unsigned int>(PRTL::Data::TOKEN))];
}