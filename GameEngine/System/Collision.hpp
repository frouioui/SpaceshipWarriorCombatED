/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include "GameEngine.hpp"
#include "Component/boundingBox.hpp"
#include "Component/destroyable.hpp"

class Collision : public ASystem {
	public:
		Collision();
		~Collision();
        void update();
    private:
        bool isCollide(boundingBox&, boundingBox&);
        bool collideSquare(boundingBox&, boundingBox&);
        bool collideSquareCircle(boundingBox&, boundingBox&);
        bool collideCircle(boundingBox&, boundingBox&);
};

#endif /* !COLLISION_HPP_ */
