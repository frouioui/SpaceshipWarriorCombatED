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
    gameEngine.insertComponent<destroyable>();
    gameEngine.insertSystem<Physic>();
    gameEngine.insertSystem<Input>();
    gameEngine.insertSystem<Collision>();
    gameEngine.insertSystem<DestroyEntity>();
}

Rtype::~Rtype()
{
}

void Rtype::update()
{
    addEventToGameEngine();
    gameEngine.updateSystem();
}

void Rtype::initGame(int nbmissile, int stage)
{
    Entity player = gameEngine.createEntity();
    _player.push_back(player);
    Signature sign;
    sign.set(gameEngine.getComponentID<rendering>());
    sign.set(gameEngine.getComponentID<boundingBox>());
    // sign.set(gameEngine.getComponentID<speed>());
    sign.set(gameEngine.getComponentID<Event>());
    sign.set(gameEngine.getComponentID<destroyable>());
    gameEngine.addComponent(player,rendering {
        {50, 10},
        {10, 10}
    });
    gameEngine.addComponent(player, boundingBox {
        SQUARE,
        {{50, 10}, {50, 20}, {60, 10}, {60, 20}}
    });
    // gameEngine.addComponent(player, speed {
    //     0
    // });
    gameEngine.addComponent(player, Event {
        1,
        NOTHING
    });
    gameEngine.addComponent(player, destroyable {
        false, false
    });
    gameEngine.setEntitySystem(player, sign);


    Entity wall = gameEngine.createEntity();
    Signature signwall;
    signwall.set(gameEngine.getComponentID<rendering>());
    signwall.set(gameEngine.getComponentID<boundingBox>());
    // signwall.set(gameEngine.getComponentID<speed>());
    signwall.set(gameEngine.getComponentID<destroyable>());
    gameEngine.addComponent(wall,rendering {
        {55, 70},
        {10, 10}
    });
    gameEngine.addComponent(wall, boundingBox {
        SQUARE,
        {{55, 70}, {55, 80}, {65, 70}, {65, 80}}
    });
    // gameEngine.addComponent(wall, speed {
    //     0
    // });
    gameEngine.addComponent(wall, destroyable {
        false, false
    });
    gameEngine.setEntitySystem(wall, signwall);
}

std::vector<boundingBox> Rtype::getBoundingBox()
{
    return gameEngine.getComponentArray<boundingBox>()->listedComponent();
}