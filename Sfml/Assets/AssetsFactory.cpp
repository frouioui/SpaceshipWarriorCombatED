/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Assets Factory
*/

#include "AssetsFactory.hpp"
#include "Player0.hpp"
#include "Player1.hpp"
#include "Player2.hpp"
#include "Player3.hpp"
#include "PlayerDie.hpp"
#include "PlayerShoot0.hpp"
#include "PlayerShoot1.hpp"
#include "Error.hpp"

Asset::AssetsFactory::AssetsFactory()
{
    _assetCreator[Asset::PLAYER0] = [this] (const std::string &ressourcesPath) {
        return this->createPlayer0(ressourcesPath);
    };
    _assetCreator[Asset::PLAYER1] = [this] (const std::string &ressourcesPath) {
        return this->createPlayer1(ressourcesPath);
    };
    _assetCreator[Asset::PLAYER2] = [this] (const std::string &ressourcesPath) {
        return this->createPlayer2(ressourcesPath);
    };
    _assetCreator[Asset::PLAYER3] = [this] (const std::string &ressourcesPath) {
        return this->createPlayer3(ressourcesPath);
    };
    _assetCreator[Asset::PLAYERDIE] = [this] (const std::string &ressourcesPath) {
        return this->createPlayerDie(ressourcesPath);
    };
    _assetCreator[Asset::PLAYERSHOOT0] = [this] (const std::string &ressourcesPath) {
        return this->createPlayerShoot0(ressourcesPath);
    };
    _assetCreator[Asset::PLAYERSHOOT1] = [this] (const std::string &ressourcesPath) {
        return this->createPlayerShoot1(ressourcesPath);
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

std::unique_ptr<Asset::IAsset> Asset::AssetsFactory::createPlayer1(const std::string &ressourcesPath) const noexcept
{
    std::unique_ptr<Asset::Player1> newPlayer1 = std::make_unique<Asset::Player1>(ressourcesPath);

    return newPlayer1;
}

std::unique_ptr<Asset::IAsset> Asset::AssetsFactory::createPlayer2(const std::string &ressourcesPath) const noexcept
{
    std::unique_ptr<Asset::Player2> newPlayer2 = std::make_unique<Asset::Player2>(ressourcesPath);

    return newPlayer2;
}

std::unique_ptr<Asset::IAsset> Asset::AssetsFactory::createPlayer3(const std::string &ressourcesPath) const noexcept
{
    std::unique_ptr<Asset::Player3> newPlayer3 = std::make_unique<Asset::Player3>(ressourcesPath);

    return newPlayer3;
}

std::unique_ptr<Asset::IAsset> Asset::AssetsFactory::createPlayerDie(const std::string &ressourcesPath) const noexcept
{
    std::unique_ptr<Asset::PlayerDie> newPlayerDie = std::make_unique<Asset::PlayerDie>(ressourcesPath);

    return newPlayerDie;
}

std::unique_ptr<Asset::IAsset> Asset::AssetsFactory::createPlayerShoot0(const std::string &ressourcesPath) const noexcept
{
    std::unique_ptr<Asset::PlayerShoot0> newPlayerShoot0 = std::make_unique<Asset::PlayerShoot0>(ressourcesPath);

    return newPlayerShoot0;
}

std::unique_ptr<Asset::IAsset> Asset::AssetsFactory::createPlayerShoot1(const std::string &ressourcesPath) const noexcept
{
    std::unique_ptr<Asset::PlayerShoot1> newPlayerShoot1 = std::make_unique<Asset::PlayerShoot1>(ressourcesPath);

    return newPlayerShoot1;
}