/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Asteroid
*/

#ifndef ASTEROID_HPP_
#define ASTEROID_HPP_

#include "AObjet.hpp"

class Asteroid : public AObjet {
	public:
		Asteroid();
		~Asteroid();
        void createObjet(std::pair<int,int> pos);
};

#endif /* !ASTEROID_HPP_ */
