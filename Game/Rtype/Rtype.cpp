/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rtype
*/

#include "Rtype.hpp"
#include <iostream>
#include "Wall/Wall.hpp"

Rtype::Rtype() : AGame()
{
    gameEngine->insertComponent<rendering>();
    gameEngine->insertComponent<boundingBox>();
    gameEngine->insertComponent<speed>();
    gameEngine->insertComponent<Event>();
    gameEngine->insertComponent<destroyable>();
    gameEngine->insertComponent<Effect>();
    gameEngine->insertComponent<Stats>();
    gameEngine->insertComponent<fromPlayer>();
    gameEngine->insertSystem<Physic>(gameEngine);
    gameEngine->insertSystem<Collision>(gameEngine);
    gameEngine->insertSystem<DestroyEntity>(gameEngine);
}

Rtype::~Rtype()
{
}

void Rtype::createBorder(int size)
{
    static int counter = 0;
    std::pair<int,int> size_obj = _objet[0]->getSize();
    if (counter % (size_obj.second + 1) == 0) {
        for (int i = 0; i < size; i++) {
            int spesize = i * size_obj.first;
            _objet[0]->createObjet({0 + spesize, MAX_WINDOW});
            _objet[0]->createObjet({MAX_WINDOW - size_obj.first - spesize, MAX_WINDOW});
        } 
        counter = 0;
    }
    counter++;
}

void Rtype::update()
{
    auto it = _event.cbegin();
    while (it != _event.cend()) {
        for (auto &x : _player)
            x->update({it->player, it->event});
        it = _event.erase(_event.begin());
		if (it != _event.cend())
			it = std::next(it);
    }
    gameEngine->updateSystem();
    createBorder(2);
}

void Rtype::initGame(int nbplayer, int stage)
{
    for (int i = 1; i <= nbplayer; i++) {
        _player.push_back(createPlayer(gameEngine ,i));
    }
    _objet.push_back(std::make_unique<Wall>(gameEngine));
}
