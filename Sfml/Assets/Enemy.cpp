/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Enemy Asset
*/

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

Asset::Enemy::Enemy(const std::string &assetPath, int height, int width):
Asset::AAsset(assetPath, "")
{
    sf::IntRect rect(0, 0, height, width);

    _nbTiles = 1;
    _tiles.push_back(rect);
    loadAsset();
}

void Asset::Enemy::loadAsset()
{
    loadTexture();
    setSprite();
}

void Asset::Enemy::setSprite() noexcept
{
    _sprite.setTexture(_texture);
    _sprite.setScale(3, 3);
    _sprite.setTextureRect(_tiles.at(_tileIndex));
}