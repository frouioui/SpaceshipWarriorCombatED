/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Player2 Asset
*/

#include <SFML/Graphics.hpp>
#include "Player2.hpp"

Asset::Player2::Player2(const std::string &ressourcesPath):
Asset::AAsset(ressourcesPath, "r-typesheet42.gif")
{
    sf::IntRect rect(0, 34, 33, 17);

    _nbTiles = 7;
    for (int i = 0; i < 4; i++) {
        _tiles.push_back(rect);
        rect.left += 33;
    }
    rect.left -= 33;
    for (int i = 0; i < 3; i++) {
        rect.left -= 33;
        _tiles.push_back(rect);
    }
    loadAsset();
}

void Asset::Player2::loadAsset()
{
    loadTexture();
    setSprite();
}

void Asset::Player2::setSprite() noexcept
{
    _sprite.setTexture(_texture);
    _sprite.setScale(3, 3);
    _sprite.setTextureRect(_tiles.at(_tileIndex));
}