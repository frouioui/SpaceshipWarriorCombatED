/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Asteroid
*/

#ifndef ASTEROID_HPP_
#define ASTEROID_HPP_

#include "AObjet.hpp"
#include "RandomSystem.hpp"

class Asteroid : public AObjet {
	public:
		Asteroid();
		~Asteroid();
        void createObjet(std::pair<int, int> pos);
		void setGameEngine(std::shared_ptr<GameEngine>& ge);
		std::shared_ptr<ASystem> getSystem();
};

#endif /* !ASTEROID_HPP_ */
