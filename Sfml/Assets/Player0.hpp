/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Player0
*/

#ifndef PLAYER0_HPP_
#define PLAYER0_HPP_

#include "AAsset.hpp"

namespace Asset {
    class Player0: public Asset::AAsset {
        public:
            Player0(const std::string &);
            ~Player0() = default;

        private:
            void loadAsset() final;
            void setSprite() noexcept final;
    }; /* !Player0 */
} /* !Asset */

#endif /* !PLAYER0_HPP_ */