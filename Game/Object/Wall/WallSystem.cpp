/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** WallSystem
*/

#include "WallSystem.hpp"

WallSystem::WallSystem() : ASystem(), _clock(), _wall(std::make_unique<Wall>()), _size(1)
{
}

WallSystem::~WallSystem()
{
}


void WallSystem::init()
{
    _wall->setGameEngine(gameEngine);
    Signature sign;
    sign.set(gameEngine->getComponentID<wallComponent>());
    _clock = std::chrono::system_clock::now();
    _size = 1;
    setSignature(sign);
    activate(true);
}

void WallSystem::update()
{
    if (!_activate)
        return;
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now-_clock).count();
    if (elapsed > (1000 / 60) * (_wall->getSize().second + 1)) {
        _clock = now;
        std::pair<int,int> size_obj = _wall->getSize();
        for (int i = 0; i < _size; i++) {
            int spesize = i * size_obj.first;
            _wall->createObjet({0 + spesize, MAX_WINDOW});
            _wall->createObjet({MAX_WINDOW - size_obj.first - spesize, MAX_WINDOW});
        }
    }
}