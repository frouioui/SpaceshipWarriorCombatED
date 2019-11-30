/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rusher
*/

#ifndef RUSHER_HPP_
#define RUSHER_HPP_
#include "IEnemy.hpp"

class Rusher : public IEnemy {
	public:
		Rusher();
		~Rusher();
        void createEnemy(std::pair<int, int> pos);
        void setGameEngine(std::shared_ptr<GameEngine>& ge);
	protected:
	private:
        std::shared_ptr<GameEngine> gameEngine;
        std::pair<int,int> _size;
};

#endif /* !RUSHER_HPP_ */
