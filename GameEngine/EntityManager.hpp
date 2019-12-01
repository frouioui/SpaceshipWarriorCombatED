/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include "ECS.hpp"
#include "Error.hpp"
#include <queue>
#include <array>

using namespace ECS;

class EntityManager {
	public:
		EntityManager();
		~EntityManager();
                Entity createEntity();
                void destroyEntity(Entity id);
                void setSignature(Entity id, Signature sign);
                Signature getSignature(Entity id);
	private:
                std::queue<Entity> _availableID;
                std::array<Signature, MAX_ENTITY> _SignatureList;
                unsigned int _entityNumber;
};

#endif /* !ENTITYMANAGER_HPP_ */
