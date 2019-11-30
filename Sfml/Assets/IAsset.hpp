/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Assets Interface
*/

#ifndef IASSET_HPP_
#define IASSET_HPP_

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"

namespace Asset {
    class IAsset {
        public:
            virtual ~IAsset() = default;

            virtual void updateSprite(float x, float y) noexcept = 0;
            virtual const sf::Sprite &getSprite() const noexcept = 0;

        private:
            virtual void loadAsset() = 0;
            virtual void loadTexture() = 0;
            virtual void setSprite() noexcept = 0;
    }; /* !IAsset */
} /* !Asset */

#endif /* !IASSET_HPP_ */