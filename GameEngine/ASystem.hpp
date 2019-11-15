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
		ASystem();
		~ASystem();
        std::set<ECS::Entity> _entities;
};

#endif /* !ASYSTEM_HPP_ */
