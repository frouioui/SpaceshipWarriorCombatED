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

unsigned short ClientManager::generatePlayerId() const
{
    unsigned short id = 0;
    for (size_t i = 0; i < _clients.size(); i++) {
        if (_clients[i].getPlayerId() != id) {
            return id;
        }
        id++;
    }
    return id;
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

Client &ClientManager::getClientByPlayerId(unsigned short player_id)
{
    static Client client;
    for (auto &&i : _clients) {
        if (player_id == i.getPlayerId()) {
            return i;
        }
    }
    return client;
}

Client &ClientManager::getClientByToken(const std::string &token)
{
    static Client client;
    for (auto &&i : _clients) {
        if (token == i.getToken()) {
            return i;
        }
    }
    return client;
}

std::vector<Client> &ClientManager::getAllClients()
{
    return _clients;
}

bool ClientManager::isAllReady() const
{
    for (size_t i = 0; i < _clients.size(); i++) {
        if (_clients[i].isConnected()) {
            if (_clients[i].isReady() == false) {
                return false;
            } 
        }
    }
    return true;
}

bool ClientManager::isClientConnected(const std::string &auth_token)
{
    if (getClientByToken(auth_token).isConnected() == true)
        return true;
    return false;
}

void ClientManager::disconnectClient(const std::string &auth_token)
{
    getClientByToken(auth_token).disconnect();
}