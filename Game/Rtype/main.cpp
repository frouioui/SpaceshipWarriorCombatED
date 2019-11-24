/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** main
*/

#include "Rtype.hpp"
#include "Sfml.hpp"

GameEngine gameEngine;

int main()
{
    std::unique_ptr<IGame> game = std::make_unique<Rtype>();
    return 0;
}