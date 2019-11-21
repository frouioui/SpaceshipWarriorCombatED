#include <iostream>
#include <map>
#include "UDP.hpp"

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
    std::cout << "begin" << std::endl;
    std::cout << archive_data << std::endl;
    std::cout << "end" << std::endl;
    std::unordered_map<std::string, std::string> map = stringToMap(archive_data);
    map["ip"] = _endpoint.address().to_string();
    map["port"] = std::to_string(_endpoint.port());
}

void UDP::send(const std::string &data, const std::string &ip, short port)
{
    std::cout << "poop" << std::endl;
    _endpoint.address(boost::asio::ip::address::from_string(ip));
    std::cout << "poop" << std::endl;
    _endpoint.port(port);
    _socket.send_to(boost::asio::buffer(data), _endpoint);
    std::cout << "sent to: " << _endpoint.address().to_string() << " on port: " << _endpoint.port() << std::endl;
}

std::unordered_map<std::string, std::string> UDP::stringToMap(std::string str) const
{
    std::unordered_map<std::string, std::string> map;

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