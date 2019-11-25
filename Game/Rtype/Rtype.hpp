/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rtype
*/

#ifndef RTYPE_HPP_
#define RTYPE_HPP_

#include "GameEngine.hpp"
#include "Component/rendering.hpp"
#include "System/Render.hpp"
#include "AGame.hpp"
#include "Physic.hpp"
#include "speed.hpp"

class Rtype : public AGame {
	public:
		Rtype();
		~Rtype();
		void initGame(int nbPlayer, int stage = 0);
		std::vector<boundingBox> getBoundingBox();
		void update();
	private:
		int _player;
		int _stage;
};

#endif /* !RTYPE_HPP_ */
