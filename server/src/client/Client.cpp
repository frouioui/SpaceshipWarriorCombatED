#include "client/Client.hpp"

Client::Client()
{
}

Client::~Client()
{
}

void Client::setIp(const std::string &ip)
{
    _ip = ip;
}

void Client::setPort(short port)
{
    _port = port;
}

void Client::setToken(const std::string &token)
{
    _token = token;
}

const std::string &Client::getIp() const
{
    return _ip;
}

short Client::getPort() const
{
    return _port;
}

const std::string &Client::getToken() const
{
    return _token;
}

void Client::setUsername(const std::string &username)
{
    _username = username;
}

const std::string &Client::getUsername() const
{
    return _username;
}