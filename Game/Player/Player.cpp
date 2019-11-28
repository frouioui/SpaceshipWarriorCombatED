/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(std::shared_ptr<GameEngine>& ge, int id) : 
_playerID(id), _isAlive(false), gameEngine(ge)
{
    if (id == 1) {
        _pos.first = 30;
        _pos.second = 5;
        _size.first = 3;
        _size.second = 4;
    }
    else if (id == 2) {
        _pos.first = 45;
        _pos.second = 5;
        _size.first = 3;
        _size.second = 4;
    }
    else if (id == 3) {
        _pos.first = 60;
        _pos.second = 5;
        _size.first = 3;
        _size.second = 4;
    }
    else if (id == 4) {
        _pos.first = 75;
        _pos.second = 5;
        _size.first = 3;
        _size.second = 4;
    }
    createEntity();
}

Player::~Player()
{
}

void Player::updatePos(const Event& event)
{
    if (event.event != NOTHING) {
        if (event.event == KEYDOWN) {
            auto& point = gameEngine->getComponent<boundingBox>(_id);
            if (point.pos[LOWERLEFT].first <= 99) {
                point.pos[UPPERLEFT].first += 1;
                point.pos[UPPERRIGHT].first += 1;
                point.pos[LOWERLEFT].first += 1;
                point.pos[LOWERRIGHT].first += 1;
            }
        }
        if (event.event == KEYUP) {
            auto& point = gameEngine->getComponent<boundingBox>(_id);
            if (point.pos[UPPERLEFT].first >= 2) {
                point.pos[UPPERLEFT].first -= 1;
                point.pos[UPPERRIGHT].first -= 1;
                point.pos[LOWERLEFT].first -= 1;
                point.pos[LOWERRIGHT].first -= 1;
            }
        }
        if (event.event == KEYLEFT) {
            auto& point = gameEngine->getComponent<boundingBox>(_id);
            if (point.pos[UPPERLEFT].second >= 2) {
                point.pos[UPPERLEFT].second -= 1;
                point.pos[UPPERRIGHT].second -= 1;
                point.pos[LOWERLEFT].second -= 1;
                point.pos[LOWERRIGHT].second -= 1;
            }
        }
        if (event.event == KEYRIGTH) {
            auto& point = gameEngine->getComponent<boundingBox>(_id);
            if (point.pos[UPPERRIGHT].second <= 99) {
                point.pos[UPPERLEFT].second += 1;
                point.pos[UPPERRIGHT].second += 1;
                point.pos[LOWERLEFT].second += 1;
                point.pos[LOWERRIGHT].second += 1;
            }
        }
    }
}

void Player::shoot()
{
    auto& point = gameEngine->getComponent<boundingBox>(_id);
    Entity missile = gameEngine->createEntity();
    Signature signmis;
    signmis.set(gameEngine->getComponentID<rendering>());
    signmis.set(gameEngine->getComponentID<destroyable>());
    signmis.set(gameEngine->getComponentID<boundingBox>());
    signmis.set(gameEngine->getComponentID<speed>());
    gameEngine->addComponent(missile,rendering {
        {point.pos[UPPERRIGHT].first + (point.pos[LOWERRIGHT].first - point.pos[UPPERRIGHT].first) / 2 - 1, point.pos[LOWERRIGHT].second + 1},
        {1, 1}
    });
    gameEngine->addComponent(missile, boundingBox {
        CIRCLE,
        {{point.pos[UPPERRIGHT].first + (point.pos[LOWERRIGHT].first - point.pos[UPPERRIGHT].first) / 2 - 1, point.pos[LOWERRIGHT].second + 1},
        {2, 0}}
    });
    gameEngine->addComponent(missile, speed {
        1
    });
    gameEngine->addComponent(missile, destroyable {
        true, false
    });
    gameEngine->setEntitySystem(missile, signmis);
}

void Player::isDestroyed()
{
    if (_isAlive) {
        auto &destroy = gameEngine->getComponent<destroyable>(_id);
        if (destroy.isDestroy) {
            gameEngine->destroyEntity(_id);
            _isAlive = false;
        }
    }
}

void Player::update(Event event)
{
    if (event.player != _playerID)
        return;
    isDestroyed();
    if (!_isAlive) {
        if ( event.event == input::SPACE)
            createEntity();
        return;
    } else {
        updatePos(event);
        if (event.event == input::SPACE)
            shoot();
    }

}

void Player::createEntity()
{
    Entity player = gameEngine->createEntity();
    Signature sign;
    sign.set(gameEngine->getComponentID<rendering>());
    sign.set(gameEngine->getComponentID<boundingBox>());
    // sign.set(gameEngine->getComponentID<speed>());
    sign.set(gameEngine->getComponentID<destroyable>());
    gameEngine->addComponent(player,rendering {
        {_pos.first, _pos.second},
        {_size.first, _size.second}
    });
    gameEngine->addComponent(player, boundingBox {
        SQUARE,
        {
            {_pos.first, _pos.second},
            {_pos.first, _pos.second + _size.second},
            {_pos.first + _size.first, _pos.second},
            {_pos.first + _size.first, _pos.second + _size.second}
        }
    });
    // gameEngine->addComponent(player, speed {
    //     0
    // });
    gameEngine->addComponent(player, destroyable {
        false, false
    });
    gameEngine->setEntitySystem(player, sign);
    _id = player;
    _isAlive = true;
}

std::unique_ptr<IPlayer> createPlayer(std::shared_ptr<GameEngine>& ge, int id)
{
    return std::make_unique<Player>(ge, id);
}