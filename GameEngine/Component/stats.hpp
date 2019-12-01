/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** player
*/

#ifndef effect
#define effect
#include "effect.hpp"

enum InfoStat {
    PLAYER,
    ENNEMY,
    OBJET
};

struct Stats
{
    int life;
    int speed;
    int dammage;
    int score;
    InfoStat type;
};


#endif /* !effect */
