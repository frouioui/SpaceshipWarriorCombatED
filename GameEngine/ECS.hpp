/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** ECS
*/

#ifndef ECS_HPP_
#define ECS_HPP_
#include <bitset>

namespace ECS {
    using Entity = unsigned int;
    using ComponentID = unsigned int;
    const Entity MAX_ENTITY = 1000;
    const ComponentID MAX_COMPONENT = 50;
    using Signature = std::bitset<MAX_COMPONENT>;
};

#endif /* !ECS_HPP_ */
