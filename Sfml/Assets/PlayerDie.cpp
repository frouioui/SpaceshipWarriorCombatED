/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** PlayerDie Asset
*/

#include <SFML/Graphics.hpp>
#include "PlayerDie.hpp"

Asset::PlayerDie::PlayerDie(const std::string &ressourcesPath):
Asset::AAsset(ressourcesPath, "r-typesheet1.gif")
{
    sf::IntRect rect(246, 303, 20, 20);

    _nbTiles = 6;
   _tiles.push_back(rect);
    rect.left = 217;
    rect.top = 298;
    rect.width = 30;
    rect.height = 30;
   _tiles.push_back(rect);
    rect.left = 181;
    rect.top = 294;
    rect.width = 35;
    rect.height = 35;
   _tiles.push_back(rect);
    rect.left = 145;
    // rect.top = 29;
   _tiles.push_back(rect);
    rect.left = 107;
    // rect.top = 298;
   _tiles.push_back(rect);
    rect.left = 71;
    // rect.top = 298;
   _tiles.push_back(rect);
    loadAsset();
}

void Asset::PlayerDie::loadAsset()
{
    loadTexture();
    setSprite();
}

void Asset::PlayerDie::setSprite() noexcept
{
    _sprite.setTexture(_texture);
    _sprite.setScale(3, 3);
    _sprite.setTextureRect(_tiles.at(_tileIndex));
}