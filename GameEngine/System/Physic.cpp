/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** Physic
*/

#include <iostream>
#include "Physic.hpp"

Physic::Physic() : ASystem()
{
    Signature sign;
    sign.set(gameEngine.getComponentID<rendering>());
    sign.set(gameEngine.getComponentID<boundingBox>());
    sign.set(gameEngine.getComponentID<speed>());
    setSignature(sign);
}

Physic::~Physic()
{
}

void Physic::update()
{
    for (auto const & x : _entities) {
        auto& point = gameEngine.getComponent<boundingBox>(x);
        auto& toto = gameEngine.getComponent<speed>(x);
        if (gameEngine.getComponent<boundingBox>(x).type == SQUARE) {
            point.pos[UPPERLEFT].second += toto.speed;
            point.pos[UPPERRIGHT].second += toto.speed;
            point.pos[LOWERLEFT].second += toto.speed;
            point.pos[LOWERRIGHT].second += toto.speed;
        }

        if (gameEngine.getComponent<boundingBox>(x).type == CIRCLE) {
            point.pos[CENTER].second += toto.speed;
        }
    }
}