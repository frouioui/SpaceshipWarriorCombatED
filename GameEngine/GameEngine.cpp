/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

GameEngine::GameEngine()
{
    _entities= std::make_unique<EntityManager>();
    _systems= std::make_unique<SystemManager>();
    _components= std::make_unique<ComponentManager>();
}

GameEngine::~GameEngine()
{
}

Entity GameEngine::createEntity()
{
    return _entities->createEntity();
}

void GameEngine::destroyEntity(Entity id)
{
    _entities->destroyEntity(id);
    _systems->destroyEntity(id);
    _components->destroyEntity(id);
}