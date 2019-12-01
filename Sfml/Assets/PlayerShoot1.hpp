/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** PlayerShoot1
*/

#ifndef PLAYERSHOOT1_HPP_
#define PLAYERSHOOT1_HPP_

#include "AAsset.hpp"

namespace Asset {
    class PlayerShoot1: public Asset::AAsset {
        public:
            PlayerShoot1(const std::string &);
            ~PlayerShoot1() = default;

        private:
            void loadAsset() final;
            void setSprite() noexcept final;
    }; /* !PlayerShoot1 */
} /* !Asset */

#endif /* !PLAYERSHOOT1_HPP_ */