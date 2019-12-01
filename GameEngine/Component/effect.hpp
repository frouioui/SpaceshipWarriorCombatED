/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** effect
*/

#ifndef EFFECT_HPP_
#define EFFECT_HPP_

enum Type {
    DAMMAGE,
    SCORE,
    SPEED,
};

struct Effect
{
    /* data */
    Type type;
    int data;
};


#endif /* !EFFECT_HPP_ */
