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
#include "IObjet.hpp"

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
        void loadObject();
        void deletePlayer(int id);
        void addPlayer();
	protected:
        std::vector<Event> _event;
        std::vector<std::unique_ptr<IEnemy>> _enemy;
        std::vector<std::unique_ptr<IObjet>> _objet;
        std::vector<std::unique_ptr<IPlayer>> _player;
		int _stage;
        std::shared_ptr<GameEngine> gameEngine;
};

#endif /* !AGAME_HPP_ */
