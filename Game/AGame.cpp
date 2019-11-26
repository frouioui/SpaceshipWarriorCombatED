/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** AGame
*/

#include "AGame.hpp"
#include <iostream>


AGame::AGame() : _event(), _enemy(), _player(), _stage(0)
{
}

AGame::~AGame()
{
}

void AGame::initGame(int nbPlayer, int stage)
{
}

void AGame::addEventToGameEngine()
{
    auto it = _event.cbegin();
    while (it != _event.cend()) {
        auto& x = gameEngine.getComponent<Event>(_player[it->player-1]);
        x.event = it->event;
        it = _event.erase(_event.begin());
		if (it != _event.cend())
			it = std::next(it);
    }
}

void AGame::addEvent(Event input)
{
    _event.push_back(input);
}

void AGame::update()
{
}

std::vector<rendering> AGame::getRendering()
{
    return gameEngine.getComponentArray<rendering>()->listedComponent();
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
