#include <iostream>
#include "client/ClientManager.hpp"

ClientManager::ClientManager()
{

}

ClientManager::~ClientManager()
{

}

void ClientManager::addClient(Client client)
{
    _clients.emplace_back(client);
}

std::string ClientManager::generateToken() const
{
    std::string token = generateOneToken();
    while (userExists(token) == true) {
        token = generateOneToken();
    }
    std::cout << "TOKEN: " << token << std::endl;
    return token;
}

std::string ClientManager::generateOneToken() const
{
    std::string token("0000000000");
    std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ/=+()-?!$&abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 10; ++i) {
        token[i] = chars[rand() % (chars.length() - 1)];
    }
    return token;
}

bool ClientManager::userExists(const std::string &token) const
{
    for (auto &&client : _clients) {
        if (client.getToken() == token) {
            return true;
        }    
    }
    return false;
}