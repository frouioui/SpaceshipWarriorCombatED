/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** IObjet
*/

#ifndef IOBJET_HPP_
#define IOBJET_HPP_

#include "GameEngine.hpp"

class IObjet {
	public:
		virtual ~IObjet() = default;
        virtual void createObject(GameEngine &gameEngine) = 0;
};

#endif /* !IOBJET_HPP_ */
