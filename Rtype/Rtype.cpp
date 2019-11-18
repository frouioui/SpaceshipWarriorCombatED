/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rtype
*/

#include "Rtype.hpp"

GameEngine gameEngine;


Rtype::Rtype()
{
    gameEngine.insertComponent<rendering>();
    gameEngine.insertSystem<Render>();
}

Rtype::~Rtype()
{
}

void Rtype::run()
{
    gameEngine.getSfml()->updateWindow();
    int counter = 0;
    while (1) {
        gameEngine.getSystem<Render>()->update();
        if (counter == 5000)
            break;
        counter++;
    }
}

void Rtype::initServer()
{
}

void Rtype::closeClient()
{
    gameEngine.getSfml()->closeWindow();
}

void Rtype::initClient()
{
    gameEngine.getSfml()->openWindow();

}