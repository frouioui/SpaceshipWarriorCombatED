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
#include <iostream>
#include <chrono>
#include <ctime>

class GameEngine;

class ASystem {
	public:
		ASystem() : _entities(), _signature(), _activate(false) {};
		~ASystem() {};
		void setGameEngine(std::shared_ptr<GameEngine>& ge) { gameEngine = ge;};
		void setSignature(Signature sign) { _signature =  sign;};
		virtual void init() = 0;
		virtual void update(const std::chrono::time_point<std::chrono::system_clock>& now) = 0;
		virtual void activate(bool isactivate) { _activate = isactivate;};
		ECS::Signature getSignature() { return _signature;};
        std::set<ECS::Entity> _entities;
	protected:
		ECS::Signature _signature;
		std::shared_ptr<GameEngine> gameEngine;
		bool _activate;
};

#endif /* !ASYSTEM_HPP_ */
