/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rtype
*/

#include "Rtype.hpp"

GameEngine gameEngine;

Rtype::Rtype() : AGame()
{
    gameEngine.insertComponent<rendering>();
    gameEngine.insertSystem<Render>();
}

Rtype::~Rtype()
{
}

void Rtype::update()
{

}
