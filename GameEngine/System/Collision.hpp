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
#include "Component/effect.hpp"
#include "Component/stats.hpp"
#include "Component/fromPlayer.hpp"
#include <math.h> 

class Collision : public ASystem {
	public:
		Collision();
		~Collision();
        void update();
        void init();
    private:
        bool isCollide(boundingBox&, boundingBox&);
        bool collideSquare(boundingBox&, boundingBox&);
        bool collideSquareCircle(boundingBox&, boundingBox&);
        bool collideCircle(boundingBox&, boundingBox&);
        float calculDistance(std::pair<int, int> point_a, std::pair<int, int> point_b);
        bool checkSideSquare(std::pair<int, int> center, int radius, std::pair<int, int>, std::pair<int, int>);
        void checkDestruction(Entity, Entity);
        void checkEffect(Entity, Entity);
        void checkScore(Entity, Entity);
};

#endif /* !COLLISION_HPP_ */
