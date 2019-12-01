/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** ShooterSystem
*/

#ifndef SHOOTERSYSTEM_HPP_
#define SHOOTERSYSTEM_HPP_

#include <chrono>
#include <ctime>

#include "Shooter.hpp"

class ShooterSystem : public ASystem {
	public:
		ShooterSystem();
		~ShooterSystem();
        void init();
        void update(const std::chrono::time_point<std::chrono::system_clock>&);
        void activate(bool);
	private:
        std::chrono::time_point<std::chrono::system_clock> _clock;
        std::unique_ptr<IObjet> _objet;
        int _size;
        int _counter;
        int _spawn;
        int _y;
        void shoot(std::pair<int,int> pos, std::pair<int,int> cible);
};

#endif /* !SHOOTERSYSTEM_HPP_ */
