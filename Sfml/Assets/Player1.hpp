/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Player1
*/

#ifndef PLAYER1_HPP_
#define PLAYER1_HPP_

#include "AAsset.hpp"

namespace Asset {
    class Player1: public Asset::AAsset {
        public:
            Player1(const std::string &);
            ~Player1() = default;

        private:
            void loadAsset() final;
            void setSprite() noexcept final;
    }; /* !Player1 */
} /* !Asset */

#endif /* !PLAYER1_HPP_ */
