/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "IPlayer.hpp"
#include "stats.hpp"

class Player : public IPlayer {
	public:
		Player(std::shared_ptr<GameEngine>&, int id);
		~Player();
                void update(Event event);
                int getPlayerID() const { return _playerID;};
	private:
                void createEntity();
                void updatePos(const Event&);
                void isDestroyed();
                void shoot();
                void shootspe();
                std::pair<int, int> _pos;
                std::pair<int, int> _size;
                int _playerID;
                bool _isAlive;
                Entity _id;

                std::chrono::time_point<std::chrono::system_clock> _clock;

                std::shared_ptr<GameEngine> gameEngine;
};

#endif /* !PLAYER_HPP_ */
