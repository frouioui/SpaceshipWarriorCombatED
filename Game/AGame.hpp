/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** AGame
*/

#ifndef AGAME_HPP_
#define AGAME_HPP_

#include "IGame.hpp"
#include "IEnemy.hpp"
#include "IPlayer.hpp"

extern GameEngine gameEngine;

class AGame : public IGame {
	public:
        AGame();
		~AGame();
        void initGame(int nbPlayer, int stage);
        void addEvent(Event input);
        void update();
        std::vector<rendering> getRendering();
        std::vector<boundingBox> getBoundingBox();
        void loadEnnemy();
        void deletePlayer(int id);
        void addPlayer();
	protected:
        std::vector<Event> _event;
        std::vector<IEnemy> _enemy;
        std::vector<std::unique_ptr<IPlayer>> _player;
		int _stage;
        std::shared_ptr<GameEngine> gameEngine;
};

#endif /* !AGAME_HPP_ */
