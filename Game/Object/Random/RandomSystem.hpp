/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** RandomSystem
*/

#ifndef RANDOMSYSTEM_HPP_
#define RANDOMSYSTEM_HPP_

#include "Asteroid.hpp"

class RandomSystem : public ASystem {
	public:
		RandomSystem();
		~RandomSystem();
        void init();
        void update(const std::chrono::time_point<std::chrono::system_clock>&);
        void activate(bool, const std::chrono::time_point<std::chrono::system_clock>& now);
	private:
        std::unique_ptr<IObjet> _objet;
        int _size;
};

#endif /* !RANDOMSYSTEM_HPP_ */
