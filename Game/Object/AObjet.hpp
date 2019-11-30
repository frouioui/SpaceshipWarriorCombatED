/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** AObjet
*/

#ifndef AOBJET_HPP_
#define AOBJET_HPP_

#include "IObjet.hpp"

class AObjet : public IObjet {
	public:
		AObjet() : gameEngine(), _size() {};
		~AObjet() {};
                void setGameEngine(std::shared_ptr<GameEngine>& ge) { gameEngine = ge;};
                void setSize(std::pair<int,int> size) { _size = size;};
                virtual void createObjet(std::pair<int,int> pos) = 0;
                std::pair<int,int> getSize() {return _size;};
	protected:
                std::shared_ptr<GameEngine> gameEngine;
                std::pair<int,int>_size;

};

#endif /* !AOBJET_HPP_ */