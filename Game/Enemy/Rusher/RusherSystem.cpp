/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** RusherSystem
*/

#include "RusherSystem.hpp"

RusherSystem::RusherSystem() : ASystem(), _clock(), _objet(std::make_unique<Rusher>()), _size(1), _counter(0), _spawn(0), _y(0)
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
    if (!_activate)
        return;
    long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now-_clock).count();
    if (elapsed > (1000 / 60)) {
        _clock = now;
        _counter++;
        if (_counter % 150 == 0) {
            _y = rand() % 100 + 75;
            _spawn++;
            _objet->createObjet({_y, MAX_WINDOW});
            _counter = 0;
        }
        if (_spawn && _counter % (_objet->getSize().first * 2 + 3) == 0) {
            _counter = 0;
            _objet->createObjet({_y, MAX_WINDOW});
            _spawn++;
        }
        if (_spawn > 5)
            _spawn = 0;
    }
}