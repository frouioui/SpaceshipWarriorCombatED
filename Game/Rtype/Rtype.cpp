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
    gameEngine->insertComponent<playerComponent>();
    gameEngine->insertComponent<fromPlayer>();
    gameEngine->insertSystem<Physic>(gameEngine);
    gameEngine->insertSystem<Collision>(gameEngine);
    gameEngine->insertSystem<DestroyEntity>(gameEngine);
}

Rtype::~Rtype()
{
}

void Rtype::update()
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now-_clock).count();
    auto it = _event.cbegin();
    while (it != _event.cend()) {
        for (auto &x : _player)
            x->update({it->player, it->event});
        it = _event.erase(_event.begin());
		if (it != _event.cend())
			it = std::next(it);
    }
    if (elapsed < (1000 / 32)) {
        _counter++;
        _clock = now;
    }
    gameEngine->updateSystem();
}

void Rtype::initGame(int nbplayer, int stage)
{
    _clock = std::chrono::system_clock::now();
    for (int i = 1; i <= nbplayer; i++) {
        _player.push_back(createPlayer(gameEngine ,i));
    }
    try {loadWallObject();} catch (std::exception &e) {std::cout << e.what() << std::endl;}
    try {loadRandomObject();} catch (std::exception &e) {std::cout << e.what() << std::endl;}
    try {loadEnnemy();} catch (std::exception &e) {std::cout << e.what() << std::endl;}
    _wall[0]->getSystem()->activate(true,_clock);
    _objet[0]->getSystem()->activate(true,_clock);
    _enemy[0]->getSystem()->activate(true,_clock);
    _enemy[1]->getSystem()->activate(true,_clock);
}
