/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Rtype
*/

#include "Rtype.hpp"
#include <iostream>

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
    if (!(_wall.size() > 0))
        return;
    static int counter = 0;
    static int random = rand() % _wall.size();
    std::pair<int,int> size_obj = _wall[random]->getSize();
    if (counter % (size_obj.second + 1) == 0) {
        random = rand() % _wall.size();
        for (int i = 0; i < size; i++) {
            int spesize = i * size_obj.first;
            _wall[random]->createObjet({0 + spesize, MAX_WINDOW});
            _wall[random]->createObjet({MAX_WINDOW - size_obj.first - spesize, MAX_WINDOW});
        }
        counter = 0;
    }
    counter++;
}

void Rtype::createRandomObject(int nb)
{
    if (!(_objet.size() > 0))
        return;
    int pos_y = 0;
    int counter = rand() % 2;
    if (counter == 1)
        pos_y = rand() % 60;
    else
        pos_y = rand() % 60 + 180;
    for (int i = 0; i < nb; i++) {
        int random = rand() % _objet.size();
        _objet[random]->createObjet({pos_y, MAX_WINDOW});
    }

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
    static bool counter = false;
    if (!counter) {
        createRandomObject(1);
        counter = true;
    }
    createBorder(1);
}

void Rtype::initGame(int nbplayer, int stage)
{
    for (int i = 1; i <= nbplayer; i++) {
        _player.push_back(createPlayer(gameEngine ,i));
    }
    try {loadWallObject();} catch (std::exception &e) {std::cout << e.what() << std::endl;}
    try {loadRandomObject();} catch (std::exception &e) {std::cout << e.what() << std::endl;}
    try {loadEnnemy();} catch (std::exception &e) {std::cout << e.what() << std::endl;}
}
