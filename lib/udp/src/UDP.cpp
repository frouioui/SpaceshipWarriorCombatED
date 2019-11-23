#include <iostream>
#include <map>
#include "UDP.hpp"
#include "Packet.hpp"

UDP::~UDP()
{
    if (_socket.is_open() == true) {
        _socket.close();
    }
}

void UDP::receive()
{
    std::string archive_data(1024, 0);
    _socket.receive_from(boost::asio::buffer(archive_data), _endpoint);
    std::cout << "received: ";
    std::cout << archive_data << std::endl;
    dataPacket data = stringToMap(archive_data);

    // goes into the packet and not into data
    data["ip"] = _endpoint.address().to_string();
    data["port"] = std::to_string(_endpoint.port());

    // transform data into packet

    // return packet
}

void UDP::send(Packet packet)
{
    _endpoint.address(packet.getIpAddress());
    _endpoint.port(packet.getPort());
    _socket.send_to(boost::asio::buffer(mapToString(packet.getData())), _endpoint);
    std::cout << "sent to: " << _endpoint.address().to_string() << " on port: " << _endpoint.port() << std::endl;
}

dataPacket UDP::stringToMap(std::string str) const
{
    dataPacket map;

    size_t posSecond = 0;
    while ((posSecond = str.find(":")) != std::string::npos) {
        std::string second = str.substr(0, posSecond);
        size_t posFirst = second.find("=");
        std::string first = second.substr(0, posFirst);
        second.erase(0, posFirst + 1);
        map[first] = second;
        str.erase(0, posSecond + 1);
    }
    return (map);
}

std::string UDP::mapToString(const dataPacket &map) const
{
    std::string string;

    for (auto it = map.cbegin(); it != map.cend();)
    {
        string += it->first;
        string += "=";
        string += it->second;
        it = std::next(it);
        string += ":";
    }
    return (string);
}