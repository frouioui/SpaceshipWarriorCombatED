/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** PlayerDie
*/

#ifndef PLAYERDIE_HPP_
#define PLAYERDIE_HPP_

#include "AAsset.hpp"

namespace Asset {
    class PlayerDie: public Asset::AAsset {
        public:
            PlayerDie(const std::string &);
            ~PlayerDie() = default;

        private:
            void loadAsset() final;
            void setSprite() noexcept final;
    }; /* !PlayerDie */
} /* !Asset */

#endif /* !PLAYERDIE_HPP_ */