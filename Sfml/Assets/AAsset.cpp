/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Asset Abstract class
*/

#include "AAsset.hpp"
#include "Error.hpp"

Asset::AAsset::AAsset(const std::string &ressourcesPath, const std::string &assetPath):
 _tiles(), _nbTiles(), _tileIndex(0), _sprite(), _texture(),
_state(Asset::DISABLE), _ressourcesPath(ressourcesPath), _assetPath(assetPath)
{
}

Asset::State Asset::AAsset::getState() const noexcept
{
    return _state;
}

void Asset::AAsset::setState(Asset::State state) noexcept
{
    _state = state;
}

void Asset::AAsset::updateSprite(float x, float y) noexcept
{
    if (_tileIndex == _nbTiles - 1)
        _tileIndex = 0;
    else
        _tileIndex += 1;
    _sprite.setTextureRect(_tiles.at(_tileIndex));
    _sprite.setPosition(x, y);
}

const sf::Sprite &Asset::AAsset::getSprite() const noexcept
{
    return _sprite;
}

void Asset::AAsset::loadTexture()
{
    if (!_texture.loadFromFile(_ressourcesPath + _assetPath))
        throw Error::Sfml::AssetError("Failed to load texture", "AAsset::loadTexture");
}