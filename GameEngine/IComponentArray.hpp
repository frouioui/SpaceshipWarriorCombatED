/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** IComponentArray
*/

#ifndef ICOMPONENTARRAY_HPP_
#define ICOMPONENTARRAY_HPP_

#include "ECS.hpp"


class IComponentArray {
	public:
		virtual ~IComponentArray();
        virtual void destroyEntity(ECS::Entity id) = 0;
};

#endif /* !ICOMPONENTARRAY_HPP_ */
