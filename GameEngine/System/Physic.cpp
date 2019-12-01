/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** Physic
*/

#include <iostream>
#include "Physic.hpp"

Physic::Physic() : ASystem(), _clock()
{
}

Physic::~Physic()
{
}

void Physic::init()
{
    _clock = std::chrono::system_clock::now();
    Signature sign;
    sign.set(gameEngine->getComponentID<rendering>());
    sign.set(gameEngine->getComponentID<boundingBox>());
    sign.set(gameEngine->getComponentID<speed>());
    setSignature(sign);
}

void Physic::update(const std::chrono::time_point<std::chrono::system_clock>& now)
{
    long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now-_clock).count();
    if (elapsed > (1000 / 60)) {
        _clock = now;
        for (auto const & x : _entities) {
            auto& point = gameEngine->getComponent<boundingBox>(x);
            auto& speedy = gameEngine->getComponent<speed>(x);
            auto& renders = gameEngine->getComponent<rendering>(x);
            if (gameEngine->getComponent<boundingBox>(x).type == SQUARE) {
                point.pos[UPPERLEFT].second += speedy.speed;
                point.pos[UPPERRIGHT].second += speedy.speed;
                point.pos[LOWERLEFT].second += speedy.speed;
                point.pos[LOWERRIGHT].second += speedy.speed;
                point.pos[UPPERLEFT].first += speedy.calc(point.pos[UPPERLEFT].second);
                point.pos[UPPERRIGHT].first += speedy.calc(point.pos[UPPERRIGHT].second);
                point.pos[LOWERLEFT].first += speedy.calc(point.pos[LOWERLEFT].second);
                point.pos[LOWERRIGHT].first += speedy.calc(point.pos[LOWERRIGHT].second);
            }

            if (gameEngine->getComponent<boundingBox>(x).type == CIRCLE) {
                point.pos[CENTER].second += speedy.speed;
                point.pos[CENTER].first += speedy.calc(point.pos[CENTER].second);
            }
            renders.pos[0] += speedy.speed;
            renders.pos[1] += speedy.calc(renders.pos[0]);
        }
    }
}