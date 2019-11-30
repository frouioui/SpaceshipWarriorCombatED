/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rusher
*/

#include "Rusher.hpp"
#include <math.h>

Rusher::Rusher() : gameEngine()
{
    _size = {5,5};
}

Rusher::~Rusher()
{
}

void Rusher::createEnemy(std::pair<int, int> pos)
{
    Entity rusher = gameEngine->createEntity();
    Signature signrusher;

    signrusher.set(gameEngine->getComponentID<rendering>());
    signrusher.set(gameEngine->getComponentID<boundingBox>());
    signrusher.set(gameEngine->getComponentID<speed>());
    signrusher.set(gameEngine->getComponentID<destroyable>());
    signrusher.set(gameEngine->getComponentID<Stats>());
    gameEngine->addComponent(rusher,rendering {
        Asset::ENNEMY0,
        "rusher" + std::to_string(rusher),
        {pos.first, pos.second},
        {_size.first, _size.second}
    });
    gameEngine->addComponent(rusher, boundingBox {
        CIRCLE,
        {{pos.first, pos.second},
        {5, 0}},
        collisionType::COLLIDE_ENEMY
    });
    gameEngine->addComponent(rusher, speed {
        -1,
        [] (int x) {
            return 5 * cos(x);
        }
    });
    gameEngine->addComponent(rusher, Stats {
        30,
        0,
        0,
        50,
        InfoStat::ENNEMY
    });
    gameEngine->setEntitySystem(rusher, signrusher);
}

void Rusher::setGameEngine(std::shared_ptr<GameEngine>& ge)
{
    gameEngine = ge;
}

extern "C"
{
	Rusher *allocatorEnemy()
	{
		return new Rusher();
	}

	void deleterEnemy(Rusher *ptr)
	{
		delete ptr;
	}
}