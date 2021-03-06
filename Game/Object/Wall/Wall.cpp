/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Wall
*/

#include "Wall.hpp"

Wall::Wall() : AObjet()
{
    _size = {45, 80};
}

Wall::~Wall()
{
}

void Wall::createObjet(std::pair<int, int> pos)
{
    Entity wall = gameEngine->createEntity();
    Signature signwall;
    signwall.set(gameEngine->getComponentID<rendering>());
    signwall.set(gameEngine->getComponentID<boundingBox>());
    signwall.set(gameEngine->getComponentID<speed>());
    signwall.set(gameEngine->getComponentID<destroyable>());
    signwall.set(gameEngine->getComponentID<Stats>());
    gameEngine->addComponent(wall,rendering {
        Asset::WALL,
        {"wall"},
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

void Wall::setGameEngine(std::shared_ptr<GameEngine>& ge)
{
    gameEngine = ge;
    gameEngine->insertSystem<WallSystem>(ge);
}

std::shared_ptr<ASystem> Wall::getSystem()
{
    return gameEngine->getSystem<WallSystem>();
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