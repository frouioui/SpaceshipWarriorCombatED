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

class AGame : public IGame {
	public:
        AGame();
		~AGame();
        void initGame(int nbPlayer, int stage);
        void addEvent(Event input);
        void update();
        std::vector<rendering> getRendering();
        void loadEnnemy();
        void deletePlayer(int id);
        void addPlayer();
	protected:
        std::queue<Event> _event;
        std::vector<IEnemy> _enemy;
};

#endif /* !AGAME_HPP_ */
