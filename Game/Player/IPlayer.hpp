/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** IPlayer
*/

#ifndef IPLAYER_HPP_
#define IPLAYER_HPP_

#include "event.hpp"
#include "rendering.hpp"
#include "destroyable.hpp"
#include "speed.hpp"
#include "boundingBox.hpp"
#include "effect.hpp"
#include "Component/playerComponent.hpp"
#include "Component/stats.hpp"
#include "fromPlayer.hpp"
#include "GameEngine.hpp"

class IPlayer {
	public:
		virtual ~IPlayer() = default;
        virtual void update(Event event) = 0;
        virtual int getPlayerID() const = 0;
};

std::unique_ptr<IPlayer> createPlayer(std::shared_ptr<GameEngine>& ge, int id);


#endif /* !IPLAYER_HPP_ */
