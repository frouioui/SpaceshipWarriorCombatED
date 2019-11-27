/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Assets Factory
*/

#include "AssetsFactory.hpp"
#include "Player0.hpp"
#include "Error.hpp"

Asset::AssetsFactory::AssetsFactory()
{
    _assetCreator[Asset::PLAYER0] = [this] (const std::string &ressourcesPath) {
        return this->createPlayer0(ressourcesPath);
    };
}

std::unique_ptr<Asset::IAsset> Asset::AssetsFactory::createAsset(const Asset::Type &type,
const std::string &ressourcesPath)
{
    auto it = _assetCreator.find(type);

    if (it == _assetCreator.end())
        throw Error::Sfml::AssetError("No corresponding type", "AssetsFactory");
    return it->second(ressourcesPath);
}

std::unique_ptr<Asset::IAsset> Asset::AssetsFactory::createPlayer0(const std::string &ressourcesPath) const noexcept
{
    std::unique_ptr<Asset::Player0> newPlayer0 = std::make_unique<Asset::Player0>(ressourcesPath);

    return newPlayer0;
}