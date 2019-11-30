/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** rendering
*/

#ifndef RENDERING_HPP_
#define RENDERING_HPP_

#include <iostream>
#include <vector>
#include "State.hpp"
#include "Type.hpp"

struct rendering
{
    /* rectangle have to be change with sprite, good luck Cécile */
    Asset::Type type;
    std::string id;
    std::vector<int> pos;
    std::vector<int> size;
};


#endif /* !RENDERING_HPP_ */