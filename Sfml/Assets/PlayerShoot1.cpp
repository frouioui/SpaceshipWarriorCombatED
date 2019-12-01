/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** PlayerShoot1 Asset
*/

#include <SFML/Graphics.hpp>
#include "PlayerShoot1.hpp"

Asset::PlayerShoot1::PlayerShoot1(const std::string &ressourcesPath):
Asset::AAsset(ressourcesPath, "r-typesheet2.gif")
{
    sf::IntRect rect(36, 469, 65, 35);

    _nbTiles = 4;
   _tiles.push_back(rect);
    rect.left = 104;
   _tiles.push_back(rect);
    rect.left = 168;
   _tiles.push_back(rect);
    rect.left = 236;
   _tiles.push_back(rect);
    loadAsset();
}

void Asset::PlayerShoot1::loadAsset()
{
    loadTexture();
    setSprite();
}

void Asset::PlayerShoot1::setSprite() noexcept
{
    _sprite.setTexture(_texture);
    _sprite.setScale(3, 3);
    _sprite.setTextureRect(_tiles.at(_tileIndex));
}