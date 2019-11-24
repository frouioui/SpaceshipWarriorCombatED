/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rtype
*/

#include "Rtype.hpp"

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

void Rtype::initGame(int nbplayer, int stage)
{

}
