/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** DestroyEntity
*/

#include "DestroyEntity.hpp"

DestroyEntity::DestroyEntity()
{
}

DestroyEntity::~DestroyEntity()
{
}

void DestroyEntity::init()
{
    Signature sign;
    sign.set(gameEngine->getComponentID<destroyable>());
    sign.set(gameEngine->getComponentID<boundingBox>());
    setSignature(sign);
}


bool DestroyEntity::isOutside(boundingBox &bb)
{
    return (bb.pos[0].first < -10 || bb.pos[0].second < -10 || bb.pos[0].first > 110 || bb.pos[0].second > 110);
}

void DestroyEntity::update()
{
    std::vector<Entity> tmp;
    for (auto x : _entities) {
        auto& bb1 = gameEngine->getComponent<boundingBox>(x);
        auto &dest = gameEngine->getComponent<destroyable>(x);
        if (dest.isDestroyable)
            if (dest.isDestroy || isOutside(bb1)) {
                tmp.push_back(x);
            }
        if (gameEngine->isEntityHave<Stats>(x)) {
            auto& stats = gameEngine->getComponent<Stats>(x);
            if (stats.life <= 0)
                tmp.push_back(x);
        }
        
    }
    for (auto x : tmp) {
        gameEngine->destroyEntity(x);
    }
}