/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** speed
*/

#ifndef SPEED_HPP_
#define SPEED_HPP_
#include <functional>

struct speed
{
    /* data */
    float speed;
    std::function<int(int x)> calc;
};


#endif /* !SPEED_HPP_ */
