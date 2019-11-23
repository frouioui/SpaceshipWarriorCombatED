#include "network/NetworkConfig.hpp"

NetworkConfig::NetworkConfig()
{
    // TODO: Check env variable too

    _server_ip = "127.0.0.1";
    _server_port = 99;
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