/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Render
*/

#ifndef RENDER_HPP_
#define RENDER_HPP_

#include <SFML/Graphics.hpp>
#include "GameEngine.hpp"
#include "Component/rendering.hpp"

class Render : public ASystem {
	public:
		Render();
		~Render();
		void init();
		void showMenu();
		void showCinematic();
		void showGame();
		void update(const std::chrono::time_point<std::chrono::system_clock>& now);	
	protected:
	private:


};

#endif /* !RENDER_HPP_ */
