/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** RusherSystem
*/

#ifndef RUSHERSYSTEM_HPP_
#define RUSHERSYSTEM_HPP_

#include <chrono>
#include <ctime>
#include<memory>

#include "Rusher.hpp"

class RusherSystem : public ASystem {
	public:
		RusherSystem();
		~RusherSystem();
        void init();
        void update(const std::chrono::time_point<std::chrono::system_clock>&);
        void activate(bool, const std::chrono::time_point<std::chrono::system_clock>&);
	private:
        std::shared_ptr<IObjet> _objet;
        int _size;
        int _counter;
        int _spawn;
        int _y;
};

#endif /* !RUSHERSYSTEM_HPP_ */
