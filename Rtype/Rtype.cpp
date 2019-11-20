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

}

void Rtype::initServer()
{
}

void Rtype::closeClient()
{
}

void Rtype::initClient()
{

}