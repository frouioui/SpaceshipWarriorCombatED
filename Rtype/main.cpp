/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** main
*/

#include "Rtype.hpp"
#include "Sfml.hpp"

int main()
{
//    Rtype game;
    Sfml sfml;
    sfml.openWindow();
    int i = 0;
    while (i < 500) {
        i++;
        sfml.updateWindow();
    }
    sfml.closeWindow();
    return 0;
}