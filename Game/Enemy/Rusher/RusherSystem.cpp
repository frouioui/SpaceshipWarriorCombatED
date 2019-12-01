/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** RusherSystem
*/

#include "RusherSystem.hpp"

RusherSystem::RusherSystem() : ASystem(), _clock(), _objet(std::make_unique<Rusher>()), _size(1)
{
}

RusherSystem::~RusherSystem()
{
}

void RusherSystem::init()
{
    _objet->setGameEngine(gameEngine);
    _activate = false;
}

void RusherSystem::activate(bool isActivated)
{
    if (isActivated) {
        _clock = std::chrono::system_clock::now();
        _size = 1;
        _activate = true;
    } else
        _activate = false;
}

void RusherSystem::update(const std::chrono::time_point<std::chrono::system_clock>& now)
{
    static int counter = 0;
    if (!_activate)
        return;
    long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now-_clock).count();
    if (elapsed > (1000 / 60)) {
        _clock = now;
        counter++;
    }
    if (counter % 100 == 0) {
        int pos_y = 0;
        _objet->createObjet({160, MAX_WINDOW});
        counter = 0;
    }
}