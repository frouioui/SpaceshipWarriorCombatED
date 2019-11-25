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
    gameEngine.insertComponent<boundingBox>();
    gameEngine.insertComponent<speed>();
    gameEngine.insertSystem<Physic>();
}

Rtype::~Rtype()
{
}

void Rtype::update()
{
    gameEngine.getSystem<Physic>()->update();
}

void Rtype::initGame(int nbplayer, int stage)
{
    Entity player = gameEngine.createEntity();
    Signature sign;
    sign.set(gameEngine.getComponentID<rendering>());
    sign.set(gameEngine.getComponentID<boundingBox>());
    sign.set(gameEngine.getComponentID<speed>());
    gameEngine.addComponent(player,rendering {
        {50, 10},
        {10, 10}
    });
    gameEngine.addComponent(player, boundingBox {
        SQUARE,
        {{50, 10}, {50, 20}, {60, 10}, {60, 20}}
    });
    gameEngine.addComponent(player, speed {
        1
    });
}

std::vector<boundingBox> Rtype::getBoundingBox()
{
    return gameEngine.getComponentArray<boundingBox>()->listedComponent();
}