#include "network/NetworkConfig.hpp"

NetworkConfig::NetworkConfig()
{
    // TODO: Check env variable too

    _server_ip = "127.0.0.1";
    _server_port = 2000;
}

NetworkConfig::NetworkConfig(const std::string &server_ip, short server_port)
{
    _server_ip = server_ip;
    _server_port = server_port;
}

NetworkConfig::~NetworkConfig()
{
}

const std::string &NetworkConfig::getServerIp() const
{
    return _server_ip;
}

short NetworkConfig::getServerPort() const
{
    return _server_port;
}

const std::string &NetworkConfig::getGameServerIp() const
{
    return _game_server_ip;
}

short NetworkConfig::getGameServerPort() const
{
    return _game_server_port;
}

void NetworkConfig::setServerIp(const std::string &ip)
{
    _server_ip = ip;
}

void NetworkConfig::setGameServerIp(const std::string &ip)
{
    _game_server_ip = ip;
}

void NetworkConfig::setServerPort(unsigned short port)
{
    _server_port = port;
}

void NetworkConfig::setGameServerPort(unsigned short port)
{
    _game_server_port = port;
}