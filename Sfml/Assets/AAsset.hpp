/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Assets Abstract Class
*/

#ifndef AASSET_HPP_
#define AASSET_HPP_

#include "IAsset.hpp"

namespace Asset {
    class AAsset: public Asset::IAsset {
        public:
            AAsset(const std::string &ressourcesPath, const std::string &assetPath);
            ~AAsset() = default;

            Asset::State getState() const noexcept final;
            void setState(Asset::State) noexcept final;

            void updateSprite(float x, float y) noexcept override;
            const sf::Sprite &getSprite() const noexcept final;

        protected:
            void loadTexture() final;

            std::vector<sf::IntRect> _tiles;
            int _nbTiles;
            int _tileIndex;
            sf::Sprite _sprite;
            sf::Texture _texture;

        private:
            virtual void loadAsset() = 0;
            virtual void setSprite() noexcept = 0;

            Asset::State _state;
            std::string _ressourcesPath;
            std::string _assetPath;

    }; /* AAsset */
} /* !Assest */

#endif /* !AASSET_HPP_ */