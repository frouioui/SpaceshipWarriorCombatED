/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** SystemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include <memory>
#include <unordered_map>
#include "ECS.hpp"
#include "ASystem.hpp"

using namespace ECS;

class SystemManager {
	public:
		SystemManager() {};
		~SystemManager() {};

        template<typename T>
        void insertSystem() {
            std::string name = typeid(T).name();
            if (_systems.find(name) == _systems.end()) {
                _systems.insert({name, std::make_shared<T>()});
            } else
                throw std::exception();
        }

        template<typename T>
        void setSignature(Signature sign) {
            std::string name = typeid(T).name();
            if (_systems.find(name) != _systems.end()) {
                _signatures.insert({name, sign});
            } else
                throw std::exception();
        }

        void changeSignatureFromEntity(Entity id, Signature sign) {
            for (auto const& x : _systems) {
                if ((sign & _signatures[x.first]) == _signatures[x.first])
                    x.second->_entities.insert(id);
                else
                    x.second->_entities.erase(id);
            }
        }

        void destroyEntity(Entity id) {
            for (auto const & x : _systems)
                x.second->_entities.erase(id);                
        }
	private:
        std::unordered_map<std::string, Signature> _signatures;
        std::unordered_map<std::string, std::shared_ptr<ASystem>> _systems;
};

#endif /* !SYSTEMMANAGER_HPP_ */
