/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

enum input {
    UP,
    DOWN,
    RIGTH,
    LEFT,
    SPACE,
    ENTER,
};

struct Event
{
    /* data */
    int player;
    input event;
};


#endif /* !EVENT_HPP_ */
