/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** Collision
*/

#include "Collision.hpp"

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::init()
{
    Signature sign;
    sign.set(gameEngine->getComponentID<boundingBox>());
    setSignature(sign);
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
    if (circle.pos[CENTER].first +  2 * radius >= square.pos[UPPERLEFT].first && circle.pos[CENTER].first - 2 * radius <= square.pos[LOWERLEFT].first)
        if  (circle.pos[CENTER].second +  2 * radius >= square.pos[UPPERLEFT].second && circle.pos[CENTER].second - 2 * radius <= square.pos[UPPERRIGHT].second)
            return (checkSideSquare(center, radius, square.pos[UPPERLEFT], square.pos[LOWERLEFT])  ||       // Left
                    checkSideSquare(center, radius, square.pos[UPPERLEFT], square.pos[UPPERRIGHT])    ||    // Up
                    checkSideSquare(center, radius, square.pos[UPPERRIGHT], square.pos[LOWERRIGHT]) ||      // Right
                    checkSideSquare(center, radius, square.pos[LOWERRIGHT], square.pos[LOWERLEFT])          // Down
            );
    return false;
}

bool Collision::collideCircle(boundingBox& c1, boundingBox& c2)
{
    std::pair<int, int> center1 = {c1.pos[CENTER].first, c1.pos[CENTER].second};
    std::pair<int, int> center2 = {c2.pos[CENTER].first, c2.pos[CENTER].second};
    int radius1 = c1.pos[RADIUS].first;
    int radius2 = c2.pos[RADIUS].first;
    if (calculDistance(center1,center2) <= radius1 + radius2)
        return true;
    return false;
}

bool Collision::isCollide(boundingBox& bb1, boundingBox& bb2)
{
    if (bb1.collideType == bb2.collideType)
        return false;
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

void Collision::checkDestruction(Entity one, Entity two)
{
    if (gameEngine->isEntityHave<destroyable>(one) && gameEngine->isEntityHave<destroyable>(two)) {
        auto &destroy = gameEngine->getComponent<destroyable>(one);
        destroy.isDestroy = true;
        auto &destroy2 = gameEngine->getComponent<destroyable>(two);
        destroy2.isDestroy = true;
    }
}

void Collision::checkEffect(Entity one, Entity two)
{
    if (gameEngine->isEntityHave<Effect>(one) && gameEngine->isEntityHave<Stats>(two)) {
        auto &effec = gameEngine->getComponent<Effect>(one);
        auto &stats = gameEngine->getComponent<Stats>(two);
        effec.type == Type::DAMMAGE ? stats.life -= effec.data : 0;
        effec.type == Type::SCORE ? stats.score += effec.data : 0;
        effec.type == Type::SPEED ? stats.speed += effec.data : 0;
    } else if (gameEngine->isEntityHave<Effect>(two) && gameEngine->isEntityHave<Stats>(one)) {
        auto &effec = gameEngine->getComponent<Effect>(two);
        auto &stats = gameEngine->getComponent<Stats>(one);
        effec.type == Type::DAMMAGE ? stats.life -= effec.data : 0;
        effec.type == Type::SCORE ? stats.score += effec.data : 0;
        effec.type == Type::SPEED ? stats.speed += effec.data : 0;
    }
}

void Collision::checkScore(Entity one, Entity two)
{
    if (gameEngine->isEntityHave<fromPlayer>(one) && gameEngine->isEntityHave<Stats>(two)) {
        auto &id = gameEngine->getComponent<fromPlayer>(one);
        auto &stats = gameEngine->getComponent<Stats>(two);
        if (stats.life <= 0) {
            auto &statsplayer = gameEngine->getComponent<Stats>(id.id);
            statsplayer.score += stats.score;
        } 
    } else if (gameEngine->isEntityHave<fromPlayer>(two) && gameEngine->isEntityHave<Stats>(one)) {
        auto &id = gameEngine->getComponent<fromPlayer>(two);
        auto &stats = gameEngine->getComponent<Stats>(one);
        if (stats.life <= 0) {
            if (gameEngine->isEntityHave<Stats>(id.id)) {
            auto &statsplayer = gameEngine->getComponent<Stats>(id.id);
            statsplayer.score += stats.score;
            }
        }
    }
}

void Collision::update(const std::chrono::time_point<std::chrono::system_clock>& now)
{
    for (auto const & x : _entities) {
         for (auto const & y : _entities) {
            if (x == y)
                continue;
            auto& bb1 = gameEngine->getComponent<boundingBox>(x);
            auto& bb2 = gameEngine->getComponent<boundingBox>(y);
            if (isCollide(bb1, bb2)) {
                checkDestruction(x, y);
                checkEffect(x, y);
                checkScore(x, y);
            }
        }
    }
}