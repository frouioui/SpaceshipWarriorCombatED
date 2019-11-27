/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** main
*/

#include "Rtype.hpp"
#include "Sfml.hpp"
#include "Client.hpp"
#include <iostream>

GameEngine gameEngine;

int main()
{
    std::unique_ptr<IGame> game = std::make_unique<Rtype>();
    // Client client;
    Sfml sfml;
    input counter = input::NOTHING;

    game->initGame(1, 0);
    sfml.loadBackground();
    sfml.loadAsset();
    sfml.openWindow();
    while (counter != input::CLOSE) {
        counter = sfml.getEvent();
        game->addEvent({1, counter});
        game->update();
        sfml.updateParallax();
        sfml.drawBoundingBox(game->getBoundingBox());
        sfml.updateWindow();
    }
    sfml.updateWindow();
    return 0;
}