/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "GameEngine.hpp"
#include "Component/event.hpp"
#include "Component/rendering.hpp"
#include "Component/boundingBox.hpp"
#include "Component/speed.hpp"
#include "Component/destroyable.hpp"

class Input : public ASystem{
	public:
		Input();
		~Input();
        void update();
	protected:
	private:
};

#endif /* !INPUT_HPP_ */
