/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** DestroyEntity
*/

#include "DestroyEntity.hpp"

DestroyEntity::DestroyEntity()
{
    Signature sign;
    sign.set(gameEngine.getComponentID<destroyable>());
    sign.set(gameEngine.getComponentID<boundingBox>());
    setSignature(sign);
}

DestroyEntity::~DestroyEntity()
{
}


bool DestroyEntity::isOutside(boundingBox &bb)
{
    return (bb.pos[0].first < -10 || bb.pos[0].second < -10 || bb.pos[0].first > 110 || bb.pos[0].second > 110);
}

void DestroyEntity::update()
{
    std::vector<Entity> tmp;
    for (auto x : _entities) {
        auto& bb1 = gameEngine.getComponent<boundingBox>(x);
        auto &dest = gameEngine.getComponent<destroyable>(x);
        if (dest.isDestroyable)
            if (dest.isDestroy || isOutside(bb1)) {
                tmp.push_back(x);
            }
        
    }
    for (auto x : tmp) {
        std::cout << x << std::endl;
        gameEngine.destroyEntity(x);
    }
}