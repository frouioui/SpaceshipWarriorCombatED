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
    _socket.receive_from(boost::asio::buffer(archive_data), _receive_endpoint);
    std::unordered_map<std::string, std::string> map = stringToMap(archive_data);
    map["ip"] = _receive_endpoint.address().to_string();
    map["port"] = std::to_string(_receive_endpoint.port());
}

void UDP::send()
{
    std::cout << "titi" << std::endl;
}

std::unordered_map<std::string, std::string> UDP::stringToMap(std::string string)
{
    std::unordered_map<std::string, std::string> map;

    size_t posSecond = 0;
    while ((posSecond = string.find(":")) != std::string::npos) {
        std::string second = string.substr(0, posSecond);
        size_t posFirst = second.find("=");
        std::string first = second.substr(0, posFirst);
        second.erase(0, posFirst + 1);
        map[first] = second;
        string.erase(0, posSecond + 1);
    }
    return (map);
}