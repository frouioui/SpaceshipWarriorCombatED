/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Asset Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include <vector>
#include "State.hpp"

namespace Asset {
    struct object_t {
        std::string id;
        Asset::State state;
        std::vector<float> pos;
    }; /* !object_t */
} /* !Asset */

#endif /* !OBJECT_HPP_ */