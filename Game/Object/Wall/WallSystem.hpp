/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** WallSystem
*/

#ifndef WALLSYSTEM_HPP_
#define WALLSYSTEM_HPP_

#include <chrono>
#include <ctime>

#include "Wall.hpp"

class WallSystem : public ASystem{
	public:
		WallSystem();
		~WallSystem();
        void init();
        void update();
	private:
        std::chrono::time_point<std::chrono::system_clock> _clock;
        std::unique_ptr<IObjet> _wall;
        int _size;
};

#endif /* !WALLSYSTEM_HPP_ */
