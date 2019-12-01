/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_
#include "AObjet.hpp"
#include "WallSystem.hpp"

class Wall : public AObjet{
	public:
		Wall();
		~Wall();
        void createObjet(std::pair<int, int> pos);
		void setGameEngine(std::shared_ptr<GameEngine>& ge);
		std::shared_ptr<ASystem> getSystem();

};

#endif /* !WALL_HPP_ */
