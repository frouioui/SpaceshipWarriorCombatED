#include "network/player/Player.hpp"

Player::Player()
{
}

Player::~Player()
{
}

void Player::setUsername(const std::string &username)
{
    _username = username;
}

const std::string &Player::getUsername() const
{
    return _username;
}