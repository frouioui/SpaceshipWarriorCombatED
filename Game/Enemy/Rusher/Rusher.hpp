/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rusher
*/

#ifndef RUSHER_HPP_
#define RUSHER_HPP_

#include "AObjet.hpp"
#include "RusherSystem.hpp"

class Rusher : public AObjet {
	public:
		Rusher();
		~Rusher();
        void createObjet(std::pair<int, int> pos);
        void setGameEngine(std::shared_ptr<GameEngine>& ge);
		std::shared_ptr<ASystem> getSystem();
	protected:
	private:
        std::string _path;
        int _height;
        int _width;
};

#endif /* !RUSHER_HPP_ */
