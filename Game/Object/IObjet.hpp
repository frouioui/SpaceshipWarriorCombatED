/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** IObjet
*/

#ifndef IOBJET_HPP_
#define IOBJET_HPP_

#include "GameEngine.hpp"
#include "rendering.hpp"
#include "boundingBox.hpp"
#include "destroyable.hpp"
#include "stats.hpp"
#include "speed.hpp"

class IObjet {
	public:
		virtual ~IObjet() = default;
        virtual void createObjet(std::pair<int, int> pos) = 0;
        virtual std::pair<int,int>getSize() = 0;
};

#endif /* !IOBJET_HPP_ */
