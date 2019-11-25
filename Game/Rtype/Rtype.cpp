/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rtype
*/

#include "Rtype.hpp"
#include <iostream>

Rtype::Rtype() : AGame()
{
    gameEngine.insertComponent<rendering>();
    gameEngine.insertComponent<boundingBox>();
    gameEngine.insertComponent<speed>();
    gameEngine.insertComponent<Event>();
    gameEngine.insertSystem<Physic>();
    gameEngine.insertSystem<Input>();

}

Rtype::~Rtype()
{
}

void Rtype::update()
{
    addEventToGameEngine();
    gameEngine.getSystem<Input>()->update();
    gameEngine.getSystem<Physic>()->update();
}

void Rtype::initGame(int nbplayer, int stage)
{
    Entity player = gameEngine.createEntity();
    _player.push_back(player);
    Signature sign;
    sign.set(gameEngine.getComponentID<rendering>());
    sign.set(gameEngine.getComponentID<boundingBox>());
    sign.set(gameEngine.getComponentID<speed>());
    sign.set(gameEngine.getComponentID<Event>());
    gameEngine.addComponent(player,rendering {
        {50, 10},
        {10, 10}
    });
    gameEngine.addComponent(player, boundingBox {
        SQUARE,
        {{50, 10}, {50, 20}, {60, 10}, {60, 20}}
    });
    gameEngine.addComponent(player, speed {
        0
    });
    gameEngine.addComponent(player, Event {
        1,
        NOTHING
    });
    gameEngine.setEntitySystem(player, sign);
}

std::vector<boundingBox> Rtype::getBoundingBox()
{
    return gameEngine.getComponentArray<boundingBox>()->listedComponent();
}