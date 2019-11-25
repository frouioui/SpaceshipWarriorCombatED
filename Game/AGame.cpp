/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** AGame
*/

#include "AGame.hpp"


AGame::AGame() : _event(), _enemy()
{
}

AGame::~AGame()
{
}

void AGame::initGame(int nbPlayer, int stage)
{
}

void AGame::addEvent(Event input)
{
    _event.push(input);
}

void AGame::update()
{
}

std::vector<rendering> AGame::getRendering()
{
    return std::vector<rendering>();
}

std::vector<boundingBox> AGame::getBoundingBox()
{
    return gameEngine.getComponentArray<boundingBox>()->listedComponent();
}


void AGame::loadEnnemy()
{

}

void AGame::deletePlayer(int id)
{

}

void AGame::addPlayer()
{

}
