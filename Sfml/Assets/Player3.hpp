/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Player3
*/

#ifndef PLAYER3_HPP_
#define PLAYER3_HPP_

#include "AAsset.hpp"

namespace Asset {
    class Player3: public Asset::AAsset {
        public:
            Player3(const std::string &);
            ~Player3() = default;

        private:
            void loadAsset() final;
            void setSprite() noexcept final;
    }; /* !Player3 */
} /* !Asset */

#endif /* !PLAYER3_HPP_ */