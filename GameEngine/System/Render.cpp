/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Render
*/

#include "Render.hpp"

Render::Render() : ASystem()
{
}

Render::~Render()
{
}

void Render::init()
{
    Signature sign;
    sign.set(gameEngine->getComponentID<rendering>());
    setSignature(sign);
}

void Render::update()
{
    for (auto const& x :_entities) {
        auto& entity = gameEngine->getComponent<rendering>(x);
        // TODO: NICO: la je ne sais pas quoi faire
    }
}