/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** Physic
*/

#ifndef PHYSIC_HPP_
#define PHYSIC_HPP_

#include <chrono>
#include <ctime>

#include "GameEngine.hpp"
#include "Component/rendering.hpp"
#include "Component/boundingBox.hpp"
#include "Component/speed.hpp"

class Physic : public ASystem {
	public:
		Physic();
		~Physic();
		void init();
		void update(const std::chrono::time_point<std::chrono::system_clock>& now);
	protected:
	private:
};

#endif /* !PHYSIC_HPP_ */
