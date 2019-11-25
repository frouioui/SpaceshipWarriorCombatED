/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** Input
*/

#include "Input.hpp"

Input::Input() : ASystem()
{
    Signature sign;
    sign.set(gameEngine.getComponentID<Event>());
    setSignature(sign);
    sign.set(gameEngine.getComponentID<rendering>());
    sign.set(gameEngine.getComponentID<boundingBox>());
}

Input::~Input()
{
}

void Input::update()
{
    for (auto const & x : _entities) {
        auto & event = gameEngine.getComponent<Event>(x);
        if (event.event != NOTHING) {
            if (event.event == KEYDOWN) {
                auto& point = gameEngine.getComponent<boundingBox>(x);
                point.pos[UPPERLEFT].first += 1;
                point.pos[UPPERRIGHT].first += 1;
                point.pos[LOWERLEFT].first += 1;
                point.pos[LOWERRIGHT].first += 1;
            }
            if (event.event == KEYUP) {
                auto& point = gameEngine.getComponent<boundingBox>(x);
                point.pos[UPPERLEFT].first -= 1;
                point.pos[UPPERRIGHT].first -= 1;
                point.pos[LOWERLEFT].first -= 1;
                point.pos[LOWERRIGHT].first -= 1;
            }
            if (event.event == KEYLEFT) {
                auto& point = gameEngine.getComponent<boundingBox>(x);
                point.pos[UPPERLEFT].second -= 1;
                point.pos[UPPERRIGHT].second -= 1;
                point.pos[LOWERLEFT].second -= 1;
                point.pos[LOWERRIGHT].second -= 1;
            }
            if (event.event == KEYRIGTH) {
                auto& point = gameEngine.getComponent<boundingBox>(x);
                point.pos[UPPERLEFT].second += 1;
                point.pos[UPPERRIGHT].second += 1;
                point.pos[LOWERLEFT].second += 1;
                point.pos[LOWERRIGHT].second += 1;
            }
            event.event = NOTHING;
        }
    }
}