/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rtype
*/

#ifndef RTYPE_HPP_
#define RTYPE_HPP_

#include "GameEngine.hpp"
#include "Component/rendering.hpp"
#include "System/Render.hpp"

class Rtype {
	public:
		Rtype();
		~Rtype();
		void run();
		void initServer();
		void initClient();
		void closeClient();
	protected:
	private:
};

#endif /* !RTYPE_HPP_ */
