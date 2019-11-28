/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** DestroyEntity
*/

#ifndef DESTROYENTITY_HPP_
#define DESTROYENTITY_HPP_

#include "GameEngine.hpp"
#include "Component/destroyable.hpp"
#include "Component/boundingBox.hpp"
#include "Component/stats.hpp"

class DestroyEntity : public ASystem {
	public:
		DestroyEntity();
		~DestroyEntity();
        void update();
        void init();
	private:
        bool isOutside(boundingBox&);
};

#endif /* !DESTROYENTITY_HPP_ */
