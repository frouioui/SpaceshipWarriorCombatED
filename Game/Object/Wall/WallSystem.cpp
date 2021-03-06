/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** WallSystem
*/

#include "WallSystem.hpp"

WallSystem::WallSystem() : ASystem(), _wall(std::make_unique<Wall>()), _size(1)
{
}

WallSystem::~WallSystem()
{
}


void WallSystem::init()
{
    _wall->setGameEngine(gameEngine);
    _activate = false;
}

void WallSystem::activate(bool isActivated, const std::chrono::time_point<std::chrono::system_clock>& now)
{
    if (isActivated) {
        _clock = now;
        _size = 1;
        _activate = true;
    } else
        _activate = false;
}

void WallSystem::update(const std::chrono::time_point<std::chrono::system_clock>& now)
{
    static int counter = 0;
    if (!_activate)
        return;
    long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now-_clock).count();
    if (elapsed > (1000 / 60)) {
        _clock = now;
        counter++;
    }
    if (counter % (_wall->getSize().second + 1) == 0) {
        counter = 0;
        std::pair<int,int> size_obj = _wall->getSize();
        for (int i = 0; i < _size; i++) {
            int spesize = i * size_obj.first;
            _wall->createObjet({0 + spesize, MAX_WINDOW});
            _wall->createObjet({MAX_WINDOW - size_obj.first - spesize, MAX_WINDOW});
        }
    }
}