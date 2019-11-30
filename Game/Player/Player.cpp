/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Player
*/

#include "Player.hpp"
#include <math.h>

Player::Player(std::shared_ptr<GameEngine>& ge, int id) : 
_playerID(id), _isAlive(false), gameEngine(ge)
{
    if (id == 1) {
        _pos.first = 50;
        _pos.second = 5;
        _size.first = 10;
        _size.second = 20;
    }
    else if (id == 2) {
        _pos.first = 100;
        _pos.second = 5;
        _size.first = 10;
        _size.second = 20;
    }
    else if (id == 3) {
        _pos.first = 150;
        _pos.second = 5;
        _size.first = 10;
        _size.second = 20;
    }
    else if (id == 4) {
        _pos.first = 200;
        _pos.second = 5;
        _size.first = 10;
        _size.second = 20;
    }
    createEntity();
}

Player::~Player()
{
}

void Player::updatePos(const Event& event)
{
    auto& stats = gameEngine->getComponent<Stats>(_id);
    if (event.event != NOTHING) {
        if (event.event == KEYDOWN) {
            auto& point = gameEngine->getComponent<boundingBox>(_id);
            if (point.pos[LOWERLEFT].first <= MAX_WINDOW - 2) {
                point.pos[UPPERLEFT].first += stats.speed;
                point.pos[UPPERRIGHT].first += stats.speed;
                point.pos[LOWERLEFT].first += stats.speed;
                point.pos[LOWERRIGHT].first += stats.speed;
            }
        }
        if (event.event == KEYUP) {
            auto& point = gameEngine->getComponent<boundingBox>(_id);
            if (point.pos[UPPERLEFT].first >= 2) {
                point.pos[UPPERLEFT].first -= stats.speed;
                point.pos[UPPERRIGHT].first -= stats.speed;
                point.pos[LOWERLEFT].first -= stats.speed;
                point.pos[LOWERRIGHT].first -= stats.speed;
            }
        }
        if (event.event == KEYLEFT) {
            auto& point = gameEngine->getComponent<boundingBox>(_id);
            if (point.pos[UPPERLEFT].second >= 2) {
                point.pos[UPPERLEFT].second -= stats.speed;
                point.pos[UPPERRIGHT].second -= stats.speed;
                point.pos[LOWERLEFT].second -= stats.speed;
                point.pos[LOWERRIGHT].second -= stats.speed;
            }
        }
        if (event.event == KEYRIGTH) {
            auto& point = gameEngine->getComponent<boundingBox>(_id);
            if (point.pos[UPPERRIGHT].second <= MAX_WINDOW - 2) {
                point.pos[UPPERLEFT].second += stats.speed;
                point.pos[UPPERRIGHT].second += stats.speed;
                point.pos[LOWERLEFT].second += stats.speed;
                point.pos[LOWERRIGHT].second += stats.speed;
            }
        }
    }
}

void Player::shoot()
{
    auto& point = gameEngine->getComponent<boundingBox>(_id);
    auto& stats = gameEngine->getComponent<Stats>(_id);
    Entity missile = gameEngine->createEntity();
    Signature signmis;
    signmis.set(gameEngine->getComponentID<rendering>());
    signmis.set(gameEngine->getComponentID<destroyable>());
    signmis.set(gameEngine->getComponentID<boundingBox>());
    signmis.set(gameEngine->getComponentID<speed>());
    signmis.set(gameEngine->getComponentID<Effect>());
    signmis.set(gameEngine->getComponentID<fromPlayer>());
    gameEngine->addComponent(missile,rendering {
        {point.pos[UPPERRIGHT].first + (point.pos[LOWERRIGHT].first - point.pos[UPPERRIGHT].first) / 2 - 1, point.pos[LOWERRIGHT].second + 1},
        {1, 1}
    });
    gameEngine->addComponent(missile, boundingBox {
        CIRCLE,
        {{point.pos[UPPERRIGHT].first + (point.pos[LOWERRIGHT].first - point.pos[UPPERRIGHT].first) / 2 - 1, point.pos[LOWERRIGHT].second + 1},
        {2, 0}},
        collisionType::COLLIDE_PLAYER
    });
    gameEngine->addComponent(missile, speed {
        3,
        [] (int x) {return cos(x) * 5;}
    });
    gameEngine->addComponent(missile, destroyable {
        true, false
    });
    gameEngine->addComponent(missile, Effect {
        Type::DAMMAGE,
        stats.dammage
    });
    gameEngine->addComponent(missile, fromPlayer {
        _id
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
    sign.set(gameEngine->getComponentID<Stats>());
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
        },
        collisionType::COLLIDE_PLAYER
    });
    // gameEngine->addComponent(player, speed {
    //     0
    // });
    gameEngine->addComponent(player, destroyable {
        false, false
    });
    gameEngine->addComponent(player, Stats {
        1,
        3,
        10,
        0
    });
    gameEngine->setEntitySystem(player, sign);
    _id = player;
    _isAlive = true;
}

std::unique_ptr<IPlayer> createPlayer(std::shared_ptr<GameEngine>& ge, int id)
{
    return std::make_unique<Player>(ge, id);
}