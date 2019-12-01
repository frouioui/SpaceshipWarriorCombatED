/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** AGame
*/

#ifndef AGAME_HPP_
#define AGAME_HPP_

#include "IGame.hpp"
#include "IPlayer.hpp"
#include "IObjet.hpp"
#include "Loader.hpp"
#include "Error.hpp"

#include <iostream>
#include <dirent.h>

class AGame : public IGame {
	public:
        AGame();
		~AGame();
        virtual void initGame(int nbPlayer, int stage) = 0;
        void addEvent(Event input);
        virtual void update() = 0;
        std::vector<rendering> getRendering();
        std::vector<boundingBox> getBoundingBox();
        void loadEnnemy();
        void loadRandomObject();
        void loadWallObject();
        void deletePlayer(int id);
        void addPlayer();
	protected:
        Loader _loader;
        std::vector<void *> _lib;
        std::vector<Event> _event;
        std::vector<std::shared_ptr<IObjet>> _enemy;
        std::vector<std::shared_ptr<IObjet>> _objet;
        std::vector<std::shared_ptr<IObjet>> _wall;
        std::vector<std::unique_ptr<IPlayer>> _player;
		int _stage;
        std::shared_ptr<GameEngine> gameEngine;
};

#endif /* !AGAME_HPP_ */
