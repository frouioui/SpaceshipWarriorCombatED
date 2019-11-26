/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** Collision
*/

#include "Collision.hpp"

Collision::Collision()
{
    Signature sign;
    sign.set(gameEngine.getComponentID<boundingBox>());
    sign.set(gameEngine.getComponentID<destroyable>());
    setSignature(sign);
}

Collision::~Collision()
{
}

bool Collision::collideSquare(boundingBox& bb1, boundingBox& bb2)
{
    auto& upleft1 = bb1.pos[squarePos::UPPERLEFT];
    auto& upright1 = bb1.pos[squarePos::UPPERRIGHT];
    auto& downleft1 = bb1.pos[squarePos::LOWERLEFT];
    auto& downright1 = bb1.pos[squarePos::LOWERRIGHT];

    auto& upleft2 = bb2.pos[squarePos::UPPERLEFT];
    auto& upright2 = bb2.pos[squarePos::UPPERRIGHT];
    auto& downleft2 = bb2.pos[squarePos::LOWERLEFT];
    auto& downright2 = bb2.pos[squarePos::LOWERRIGHT];

    if ((upleft1.first >= upleft2.first && upleft1.second >= upleft2.second) &&
    (upleft1.first >= upright2.first && upleft1.second <= upright2.second) && 
    (upleft1.first <= downleft2.first && upleft1.second >= downleft2.second) &&
    (upleft1.first <= downright2.first && upleft1.second <= downright2.second))
        return true;

    if ((upright1.first >= upleft2.first && upright1.second >= upleft2.second) &&
    (upright1.first >= upright2.first && upright1.second <= upright2.second) && 
    (upright1.first <= downleft2.first && upright1.second >= downleft2.second) &&
    (upright1.first <= downright2.first && upright1.second <= downright2.second))
        return true;

    if ((downleft1.first >= upleft2.first && downleft1.second >= upleft2.second) &&
    (downleft1.first >= upright2.first && downleft1.second <= upright2.second) && 
    (downleft1.first <= downleft2.first && downleft1.second >= downleft2.second) &&
    (downleft1.first <= downright2.first && downleft1.second <= downright2.second))
        return true;

    if ((downright1.first >= upleft2.first && downright1.second >= upleft2.second) &&
    (downright1.first >= upright2.first && downright1.second <= upright2.second) && 
    (downright1.first <= downleft2.first && downright1.second >= downleft2.second) &&
    (downright1.first <= downright2.first && downright1.second <= downright2.second))
        return true;

    return false;
}

float Collision::calculDistance(std::pair<int, int> point_a, std::pair<int, int> point_b)
{
    return sqrt(pow(point_a.first - point_b.first, 2) + pow(point_a.second - point_b.second, 2));
}

bool Collision::checkSideSquare(std::pair<int, int> center, int radius, std::pair<int, int> pointA, std::pair<int, int> pointB) 
{
    int counter = 0;

    if (pointA.first != pointB.first) {
        counter = pointA.first > pointB.first ? -1 : 1;
        for (int i = pointA.first; i != pointB.first; i += counter)
            if (calculDistance(center, {i, pointA.second}) < radius)
                return true;
    } else {
        counter = pointA.second > pointB.second ? -1 : 1;
        for (int i = pointA.second; i != pointB.second; i += counter)
            if (calculDistance(center, {pointA.first, i}) < radius)
                return true;
    }
    return false;
}

bool Collision::collideSquareCircle(boundingBox& square, boundingBox& circle)
{
    int radius = circle.pos[RADIUS].first;
    std::pair<int, int> center = {circle.pos[CENTER].first + radius, circle.pos[CENTER].second};
    return (checkSideSquare(center, radius, square.pos[UPPERLEFT], square.pos[LOWERLEFT])  || // Left
            checkSideSquare(center, radius, square.pos[UPPERLEFT], square.pos[UPPERRIGHT])    || // Up
            checkSideSquare(center, radius, square.pos[UPPERRIGHT], square.pos[LOWERRIGHT]) || // Right
            checkSideSquare(center, radius, square.pos[LOWERRIGHT], square.pos[LOWERLEFT]) // Down
    );
}

bool Collision::collideCircle(boundingBox& c1, boundingBox& c2)
{
    return false;
}

bool Collision::isCollide(boundingBox& bb1, boundingBox& bb2)
{
    if (bb1.type == SQUARE && bb2.type == SQUARE)
        return collideSquare(bb1, bb2);

    if (bb1.type == CIRCLE && bb2.type == SQUARE)
        return collideSquareCircle(bb2, bb1);
    
    if (bb1.type == SQUARE && bb2.type == CIRCLE)
        return collideSquareCircle(bb1, bb2);
    
    if (bb1.type == CIRCLE && bb2.type == CIRCLE)
        return collideCircle(bb1, bb2);
    return false;
}


void Collision::update()
{
    for (auto const & x : _entities) {
         for (auto const & y : _entities) {
            if (x == y)
                continue;
            auto& bb1 = gameEngine.getComponent<boundingBox>(x);
            auto& bb2 = gameEngine.getComponent<boundingBox>(y);
            if (isCollide(bb1, bb2)) {
                auto &destroy1 = gameEngine.getComponent<destroyable>(x);
                auto &destroy2 = gameEngine.getComponent<destroyable>(y);
                destroy1.isDestroy = true;
                destroy2.isDestroy = true;
            }
        }
    } 
}