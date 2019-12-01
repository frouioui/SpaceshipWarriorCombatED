/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Shooter
*/

#include "Shooter.hpp"

Shooter::Shooter() : AObjet()
{
    _size = {10,20};
}

Shooter::~Shooter()
{
}

void Shooter::createObjet(std::pair<int, int> pos)
{
    Entity shooter = gameEngine->createEntity();
    Signature signshooter;

    signshooter.set(gameEngine->getComponentID<rendering>());
    signshooter.set(gameEngine->getComponentID<boundingBox>());
    signshooter.set(gameEngine->getComponentID<speed>());
    signshooter.set(gameEngine->getComponentID<destroyable>());
    signshooter.set(gameEngine->getComponentID<Stats>());
    signshooter.set(gameEngine->getComponentID<shooterComponent>());
    gameEngine->addComponent(shooter,rendering {
        Asset::ENNEMY0,
        "shooter" + std::to_string(shooter),
        {pos.first, pos.second},
        {_size.first, _size.second}
    });
    gameEngine->addComponent(shooter, boundingBox {
        SQUARE,
        {
            {pos.first, pos.second},
            {pos.first, pos.second + _size.second},
            {pos.first + _size.first, pos.second},
            {pos.first + _size.first, pos.second + _size.second}
        },
        collisionType::COLLIDE_ENEMY
    });
    gameEngine->addComponent(shooter, speed {
        -1,
        [] (int x) {
            return 1;
        }
    });
    gameEngine->addComponent(shooter, destroyable {
        false, false
    });
    gameEngine->addComponent(shooter, Stats {
        30,
        0,
        0,
        50,
        InfoStat::ENNEMY
    });
    gameEngine->addComponent(shooter, shooterComponent {
        gameEngine->getRandomComponent<playerComponent>()
    });
    gameEngine->setEntitySystem(shooter, signshooter);
}

void Shooter::setGameEngine(std::shared_ptr<GameEngine>& ge)
{
    gameEngine = ge;
    try {gameEngine->insertComponent<shooterComponent>();} catch (std::exception &e) {std::cout << e.what() << std::endl;}
    try {gameEngine->insertSystem<ShooterSystem>(ge);} catch (std::exception &e) {std::cout << e.what() << std::endl;}
}

std::shared_ptr<ASystem> Shooter::getSystem()
{
    return gameEngine->getSystem<ShooterSystem>();
}

extern "C"
{
	Shooter *allocatorEnemy()
	{
		return new Shooter();
	}

	void deleterEnemy(Shooter *ptr)
	{
		delete ptr;
	}
}