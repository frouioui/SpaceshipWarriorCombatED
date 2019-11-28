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
    gameEngine->insertComponent<rendering>();
    gameEngine->insertComponent<boundingBox>();
    gameEngine->insertComponent<speed>();
    gameEngine->insertComponent<Event>();
    gameEngine->insertComponent<destroyable>();
    gameEngine->insertSystem<Physic>(gameEngine);
    gameEngine->insertSystem<Collision>(gameEngine);
    gameEngine->insertSystem<DestroyEntity>(gameEngine);
}

Rtype::~Rtype()
{
}


void Rtype::update()
{
    auto it = _event.cbegin();
    while (it != _event.cend()) {
        for (auto &x : _player)
            x->update({it->player, it->event});
        it = _event.erase(_event.begin());
		if (it != _event.cend())
			it = std::next(it);
    }
    gameEngine->updateSystem();
}

void Rtype::initGame(int nbplayer, int stage)
{
    for (int i = 1; i <= nbplayer; i++) {
        _player.push_back(createPlayer(gameEngine ,i));
    }

    Entity wall = gameEngine->createEntity();
    Signature signwall;
    signwall.set(gameEngine->getComponentID<rendering>());
    signwall.set(gameEngine->getComponentID<boundingBox>());
    // signwall.set(gameEngine->getComponentID<speed>());
    signwall.set(gameEngine->getComponentID<destroyable>());
    gameEngine->addComponent(wall,rendering {
        {55, 70},
        {10, 10}
    });
    gameEngine->addComponent(wall, boundingBox {
        SQUARE,
        {{55, 70}, {55, 80}, {65, 70}, {65, 80}}
    });
    // gameEngine->addComponent(wall, speed {
    //     0
    // });
    gameEngine->addComponent(wall, destroyable {
        false, false
    });
    gameEngine->setEntitySystem(wall, signwall);
}
