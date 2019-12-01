/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "AAsset.hpp"

namespace Asset {
    class Enemy: public Asset::AAsset {
        public:
            Enemy(const std::string &assetPath, int height, int width);
            void loadAsset() final;
            void setSprite() noexcept final;
    }; /* !Enemy */
} /* !Asset */

#endif /* !ENEMY_HPP_ */