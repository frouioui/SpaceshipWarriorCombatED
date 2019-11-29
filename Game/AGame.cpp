/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** AGame
*/

#include "AGame.hpp"
#include <iostream>


AGame::AGame() : _event(), _enemy(), _objet(), _player(), _stage(0)
{
    gameEngine = std::make_shared<GameEngine>();
}

AGame::~AGame()
{
}


void AGame::addEvent(Event input)
{
    _event.push_back(input);
}

std::vector<rendering> AGame::getRendering()
{
    return gameEngine->getComponentArray<rendering>()->listedComponent();
}

std::vector<boundingBox> AGame::getBoundingBox()
{
    return gameEngine->getComponentArray<boundingBox>()->listedComponent();
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
