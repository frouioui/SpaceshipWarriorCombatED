/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** effect
*/

#ifndef EFFECT_HPP_
#define EFFECT_HPP_

namespace effect {
    enum type {
        DAMMAGE,
        BONUS,
        SPEED,
    };

    struct effect
    {
        /* data */
        int dammage;
        int bonus;
    };
}


#endif /* !EFFECT_HPP_ */
