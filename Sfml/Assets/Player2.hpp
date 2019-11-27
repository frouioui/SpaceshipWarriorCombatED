/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Player2
*/

#ifndef PLAYER2_HPP_
#define PLAYER2_HPP_

#include "AAsset.hpp"

namespace Asset {
    class Player2: public Asset::AAsset {
        public:
            Player2(const std::string &);
            ~Player2() = default;

        private:
            void loadAsset() final;
            void setSprite() noexcept final;
    }; /* !Player2 */
} /* !Asset */

#endif /* !PLAYER2_HPP_ */