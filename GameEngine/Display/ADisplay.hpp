/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** ADisplay
*/

#ifndef ADISPLAY_HPP_
#define ADISPLAY_HPP_

#include "IDisplay.hpp"

class ADisplay : public IDisplay {
	public:
		ADisplay();
		~ADisplay();
        void displayGame();
        void displayMenu();
        void displayParallax();
	protected:
	private:
};

#endif /* !ADISPLAY_HPP_ */
