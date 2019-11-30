/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_
#include "AObjet.hpp"

class Wall : public AObjet{
	public:
		Wall();
		~Wall();
        void createObjet(std::pair<int,int> pos);
};

#endif /* !WALL_HPP_ */