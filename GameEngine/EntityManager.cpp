/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

EntityManager::EntityManager() : _availableID(), _SignatureList(), _entityNumber(0)
{
    for (Entity id = 0; id < MAX_ENTITY; id++)
        _availableID.push(id);
}

EntityManager::~EntityManager()
{
}

Entity EntityManager::createEntity()
{
    if (_entityNumber >= MAX_ENTITY)
        throw Error::Error("Impossible to create Entity", "Entity Manager");
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
        throw Error::Error("Impossible to destroy Entity", "Entity Manager");
}

void EntityManager::setSignature(Entity id, Signature sign)
{
    if (id < MAX_ENTITY) {
        _SignatureList[id] = sign;
    } else
        throw Error::Error("Impossible to set Signature");
}

Signature EntityManager::getSignature(Entity id)
{
    if (id >= MAX_ENTITY)
        throw Error::Error("Impossible to get Signature from entity", "Game Engine");
    return _SignatureList[id];
}