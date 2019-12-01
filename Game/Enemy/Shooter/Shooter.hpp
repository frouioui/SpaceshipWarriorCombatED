/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Shooter
*/

#ifndef SHOOTER_HPP_
#define SHOOTER_HPP_
#include "AObjet.hpp"
#include "playerComponent.hpp"
#include "shooterComponent.hpp"
#include "ShooterSystem.hpp"

class Shooter : public AObjet {
	public:
		Shooter();
		~Shooter();
        void createObjet(std::pair<int, int> pos);
		void setGameEngine(std::shared_ptr<GameEngine>& ge);
		std::shared_ptr<ASystem> getSystem();
	protected:
	private:
};

#endif /* !SHOOTER_HPP_ */
