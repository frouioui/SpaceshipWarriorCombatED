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
    sign.set(gameEngine.getComponentID<rendering>());
    sign.set(gameEngine.getComponentID<boundingBox>());
    setSignature(sign);
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
                if (point.pos[LOWERLEFT].first <= 99) {
                    point.pos[UPPERLEFT].first += 1;
                    point.pos[UPPERRIGHT].first += 1;
                    point.pos[LOWERLEFT].first += 1;
                    point.pos[LOWERRIGHT].first += 1;
                }
            }
            if (event.event == KEYUP) {
                auto& point = gameEngine.getComponent<boundingBox>(x);
                if (point.pos[UPPERLEFT].first >= 2) {
                    point.pos[UPPERLEFT].first -= 1;
                    point.pos[UPPERRIGHT].first -= 1;
                    point.pos[LOWERLEFT].first -= 1;
                    point.pos[LOWERRIGHT].first -= 1;
                }
            }
            if (event.event == KEYLEFT) {
                auto& point = gameEngine.getComponent<boundingBox>(x);
                if (point.pos[UPPERLEFT].second >= 2) {
                    point.pos[UPPERLEFT].second -= 1;
                    point.pos[UPPERRIGHT].second -= 1;
                    point.pos[LOWERLEFT].second -= 1;
                    point.pos[LOWERRIGHT].second -= 1;
                }
            }
            if (event.event == KEYRIGTH) {
                auto& point = gameEngine.getComponent<boundingBox>(x);
                if (point.pos[UPPERRIGHT].second <= 99) {
                    point.pos[UPPERLEFT].second += 1;
                    point.pos[UPPERRIGHT].second += 1;
                    point.pos[LOWERLEFT].second += 1;
                    point.pos[LOWERRIGHT].second += 1;
                }
            }
            if (event.event == SPACE) {
                auto& point = gameEngine.getComponent<boundingBox>(x);
                Entity missile = gameEngine.createEntity();
                Signature signmis;
                signmis.set(gameEngine.getComponentID<rendering>());
                signmis.set(gameEngine.getComponentID<destroyable>());
                signmis.set(gameEngine.getComponentID<boundingBox>());
                signmis.set(gameEngine.getComponentID<speed>());
                gameEngine.addComponent(missile,rendering {
                    {point.pos[UPPERRIGHT].first + (point.pos[LOWERRIGHT].first - point.pos[UPPERRIGHT].first) / 2 - 1, point.pos[LOWERRIGHT].second + 1},
                    {1, 1}
                });
                gameEngine.addComponent(missile, boundingBox {
                    CIRCLE,
                    {{point.pos[UPPERRIGHT].first + (point.pos[LOWERRIGHT].first - point.pos[UPPERRIGHT].first) / 2 - 1, point.pos[LOWERRIGHT].second + 1},
                    {2, 0}}
                });
                gameEngine.addComponent(missile, speed {
                    1
                });
                gameEngine.addComponent(missile, destroyable {
                    true, false
                });
                gameEngine.setEntitySystem(missile, signmis);
            }
            event.event = NOTHING;
        }
    }
}