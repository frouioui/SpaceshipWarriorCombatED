/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** PlayerShoot0 Asset
*/

#include <SFML/Graphics.hpp>
#include "PlayerShoot0.hpp"

Asset::PlayerShoot0::PlayerShoot0(const std::string &ressourcesPath):
Asset::AAsset(ressourcesPath, "r-typesheet2.gif")
{
    sf::IntRect rect(184, 7, 20, 20);

    _nbTiles = 4;
   _tiles.push_back(rect);
    rect.left = 207;
    rect.width = 30;
   _tiles.push_back(rect);
    rect.left = 233;
   _tiles.push_back(rect);
    rect.left = 267;
   _tiles.push_back(rect);
    loadAsset();
}

void Asset::PlayerShoot0::loadAsset()
{
    loadTexture();
    setSprite();
}

void Asset::PlayerShoot0::setSprite() noexcept
{
    _sprite.setTexture(_texture);
    _sprite.setScale(3, 3);
    _sprite.setTextureRect(_tiles.at(_tileIndex));
}