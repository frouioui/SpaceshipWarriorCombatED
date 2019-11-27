/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** PlayerShoot0
*/

#ifndef PLAYERSHOOT0_HPP_
#define PLAYERSHOOT0_HPP_

#include "AAsset.hpp"

namespace Asset {
    class PlayerShoot0: public Asset::AAsset {
        public:
            PlayerShoot0(const std::string &);
            ~PlayerShoot0() = default;

            void updateSprite(float x, float y) noexcept final;

        private:
            void loadAsset() final;
            void setSprite() noexcept final;
    }; /* !PlayerShoot0 */
} /* !Asset */

#endif /* !PLAYERSHOOT0_HPP_ */