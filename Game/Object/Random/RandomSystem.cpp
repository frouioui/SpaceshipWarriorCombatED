/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** RandomSystem
*/

#include "RandomSystem.hpp"

RandomSystem::RandomSystem() : ASystem(), _objet(std::make_unique<Asteroid>())
{
}

RandomSystem::~RandomSystem()
{
}

void RandomSystem::init()
{
    _objet->setGameEngine(gameEngine);
    _activate = false;
}

void RandomSystem::activate(bool isActivated, const std::chrono::time_point<std::chrono::system_clock>& now)
{
    if (isActivated) {
        _clock = now;
        _size = 1;
        _activate = true;
    } else
        _activate = false;
}

void RandomSystem::update(const std::chrono::time_point<std::chrono::system_clock>& now)
{
    static int counter = 0;
    if (!_activate)
        return;
    long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now-_clock).count();
    if (elapsed > (1000 / 60)) {
        _clock = now;
        counter++;
    }
    if (counter % 40 == 0) {
        int pos_y = 0;
        counter = std::rand() % 2;
        if (counter == 1)
            pos_y = std::rand() % 60;
        else
            pos_y = std::rand() % 60 + 180;
        _objet->createObjet({pos_y, MAX_WINDOW});
        counter = 0;
    }
}