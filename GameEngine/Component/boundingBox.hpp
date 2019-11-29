/*
** EPITECH PROJECT, 2019
** GameEngine
** File description:
** boundingBox
*/

#ifndef BOUNDINGBOX_HPP_
#define BOUNDINGBOX_HPP_

#include <string>
#include <vector>

enum shapeType {
    CIRCLE,
    SQUARE,
};

enum squarePos {
    UPPERLEFT = 0,
    UPPERRIGHT = 1,
    LOWERLEFT = 2,
    LOWERRIGHT = 3
};

enum circlePos {
    CENTER = 0,
    RADIUS = 1
};

enum collisionType {
    COLLIDE_PLAYER,
    COLLIDE_ENEMY,
    COLLIDE_OBJECT,
};

struct boundingBox
{
    shapeType type;
    std::vector<std::pair<int, int>> pos;
    collisionType collideType;
};

#endif /* !BOUNDINGBOX_HPP_ */
