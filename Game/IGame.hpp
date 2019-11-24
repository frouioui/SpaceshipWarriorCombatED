/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <vector>
#include "event.hpp"
#include "rendering.hpp"
#include "GameEngine.hpp"

class IGame {
	public:
		virtual ~IGame() = default;
        virtual void initGame(int nbPlayer, int stage) = 0;
        virtual void addEvent(Event input) = 0;
        virtual void update() = 0;
        virtual std::vector<rendering> getRendering() = 0;
        virtual void loadEnnemy() = 0;
        virtual void deletePlayer(int id) = 0;
        virtual void addPlayer() = 0;
};

#endif /* !IGAME_HPP_ */
