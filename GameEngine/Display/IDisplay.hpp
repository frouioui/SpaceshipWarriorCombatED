/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include "event.h"

class IDisplay {
	public:
		virtual ~IDisplay() = default;
        virtual void displayGame() = 0;
        virtual void displayMenu() = 0;
        virtual event getInput() = 0;
};

#endif /* !IDISPLAY_HPP_ */
