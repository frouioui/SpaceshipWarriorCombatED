/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

EntityManager::EntityManager()
{
    for (Entity id = 1; id < MAX_ENTITY; id++)
        _availableID.push(id);
}

EntityManager::~EntityManager()
{
}

Entity EntityManager::createEntity()
{
    if (_entityNumber >= MAX_ENTITY)
        throw std::exception();
    _entityNumber++;
    Entity id = _availableID.front();
    _availableID.pop();
    return id;
}

void EntityManager::destroyEntity(Entity id)
{
    if (id < MAX_ENTITY) {
        _entityNumber--;
        _SignatureList[id].reset();
        _availableID.push(id);
    } else
        throw std::exception();
}

void EntityManager::setSignature(Entity id, Signature sign)
{
    if (id < MAX_ENTITY) {
        _SignatureList[id] = sign;
    } else
        throw std::exception();
}

Signature EntityManager::getSignature(Entity id)
{
    if (id >= MAX_ENTITY)
        throw std::exception();
    return _SignatureList[id];
}