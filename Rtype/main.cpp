/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** main
*/

#include "Rtype.hpp"


int main()
{
    Rtype game;
    game.initServer();
    game.initClient();
    game.run();
    game.closeClient();
    return 0;
}