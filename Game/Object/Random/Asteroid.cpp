/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Asteroid
*/

#include "Asteroid.hpp"

Asteroid::Asteroid() : AObjet()
{
    _size = {0,0};
}

Asteroid::~Asteroid()
{
}

void Asteroid::createObjet(std::pair<int,int> pos)
{
    int radius = rand() % 15;
    Entity wall = gameEngine->createEntity();
    Signature signwall;
    signwall.set(gameEngine->getComponentID<rendering>());
    signwall.set(gameEngine->getComponentID<boundingBox>());
    signwall.set(gameEngine->getComponentID<speed>());
    signwall.set(gameEngine->getComponentID<destroyable>());
    signwall.set(gameEngine->getComponentID<Stats>());
    gameEngine->addComponent(wall,rendering {
        {pos.first, pos.second},
        {_size.first, _size.second}
    });
    gameEngine->addComponent(wall, boundingBox {
        CIRCLE,
        {{pos.first, pos.second},
        {radius, 0}},
        collisionType::COLLIDE_OBJECT
    });
    gameEngine->addComponent(wall, speed {
        -1
    });
    gameEngine->addComponent(wall, destroyable {
        false, false
    });
    gameEngine->addComponent(wall, Stats {
        30,
        0,
        0,
        0,
        InfoStat::OBJET
    });
    gameEngine->setEntitySystem(wall, signwall);
}

extern "C"
{
	Asteroid *allocatorRandom()
	{
		return new Asteroid();
	}

	void deleterAsteroidRandom(Asteroid *ptr)
	{
		delete ptr;
	}
}