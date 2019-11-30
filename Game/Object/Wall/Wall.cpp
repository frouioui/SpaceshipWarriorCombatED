/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Wall
*/

#include "Wall.hpp"


Wall::Wall() : AObjet()
{
    _size = {15, 20};
}

Wall::~Wall()
{
}

void Wall::createObjet(std::pair<int,int> pos)
{
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
        SQUARE,
        {{pos.first, pos.second},
        {pos.first, pos.second + _size.second},
        {pos.first + _size.first, pos.second},
        {pos.first + _size.first, pos.second + _size.second}},
        collisionType::COLLIDE_OBJECT
    });
    gameEngine->addComponent(wall, speed {
        -1,
        [] (int x) {return 0;}
    });
    gameEngine->addComponent(wall, destroyable {
        false, false
    });
    gameEngine->addComponent(wall, Stats {
        100,
        0,
        0,
        0,
        InfoStat::OBJET
    });
    gameEngine->setEntitySystem(wall, signwall);
}

extern "C"
{
	Wall *allocatorWall()
	{
		return new Wall();
	}

	void deleterWall(Wall *ptr)
	{
		delete ptr;
	}
}