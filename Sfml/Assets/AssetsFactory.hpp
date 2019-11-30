/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** AssetsFactory declaration
*/

#ifndef ASSETSFACTORY_HPP_
#define ASSETSFACTORY_HPP_

#include <memory>
#include <unordered_map>
#include <functional>
#include "IAsset.hpp"
#include "Type.hpp"

namespace Asset {
    class AssetsFactory {
        public:
            AssetsFactory();
            ~AssetsFactory() = default;

            std::unique_ptr<Asset::IAsset> createAsset(const Asset::Type &type,
            const std::string &ressourcesPath);

        private:
            using func_t = std::function<std::unique_ptr<Asset::IAsset>(const std::string &)>;
            std::unordered_map<Asset::Type, func_t> _assetCreator;

            std::unique_ptr<Asset::IAsset> createPlayer0(const std::string &) const noexcept;
            std::unique_ptr<Asset::IAsset> createPlayer1(const std::string &) const noexcept;
            std::unique_ptr<Asset::IAsset> createPlayer2(const std::string &) const noexcept;
            std::unique_ptr<Asset::IAsset> createPlayer3(const std::string &) const noexcept;
            std::unique_ptr<Asset::IAsset> createPlayerDie(const std::string &) const noexcept;
            std::unique_ptr<Asset::IAsset> createPlayerShoot0(const std::string &) const noexcept;
            std::unique_ptr<Asset::IAsset> createPlayerShoot1(const std::string &) const noexcept;
    }; /* !AssetsFactory*/
} /* !Asset */

#endif /* !ASSETSFACTORY_HPP_ */