/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** IEnemy
*/

#ifndef IENEMY_HPP_
#define IENEMY_HPP_

#include "GameEngine.hpp"
#include "rendering.hpp"
#include "boundingBox.hpp"
#include "destroyable.hpp"
#include "stats.hpp"
#include "speed.hpp"

class IEnemy {
	public:
		virtual ~IEnemy() = default;
		virtual void createEnemy(std::pair<int, int> pos) = 0;
        virtual void setGameEngine(std::shared_ptr<GameEngine>& ge) = 0;
};

#endif /* !IENEMY_HPP_ */
