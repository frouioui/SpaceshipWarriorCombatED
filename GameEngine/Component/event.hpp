/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

enum input {
    KEYUP,
    KEYDOWN,
    KEYRIGTH,
    KEYLEFT,
    SPACE,
    ENTER,
    CLOSE,
    ECHAP,
    BUTTON1,
    BUTTON2,
    NOTHING,
    CHEAT1,
    CHEAT2,
    CHEAT3,
    CHEAT4,
    CHEAT5,
};

struct Event
{
    /* data */
    int player;
    input event;
};


#endif /* !EVENT_HPP_ */
