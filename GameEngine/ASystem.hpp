/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_

#include <set>
#include "ECS.hpp"

class GameEngine;
extern GameEngine gameEngine;

class ASystem {
	public:
		ASystem() : _entities(), _signature() {};
		~ASystem() {};
		void setSignature(Signature sign) { _signature =  sign;};
		void update() {};
		ECS::Signature getSignature() { return _signature;};
        std::set<ECS::Entity> _entities;
	protected:
		ECS::Signature _signature;
};

#endif /* !ASYSTEM_HPP_ */
