/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Render
*/

#include "Render.hpp"

Render::Render() : ASystem()
{
    Signature sign;
    sign.set(gameEngine.getComponentID<rendering>());
    setSignature(sign);
    
}

Render::~Render()
{
    
}

void Render::update()
{
    
    // for (auto const& x :_entities) {
        // rendering entity = gameEngine.getComponent<rendering>(x);
        // gameEngine.getSfml()->drawBox(entity.pos, entity.size);
    // }
}