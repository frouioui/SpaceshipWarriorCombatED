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
        void insertSystem(std::shared_ptr<GameEngine>& ge) {
            std::string name = typeid(T).name();
            if (_systems.find(name) == _systems.end()) {
                _systems.insert({name, std::make_shared<T>()});
                _systems[name]->setGameEngine(ge);
                _systems[name]->init();
            } else
                throw Error::Error("Impossible to insert System " + name, "System Manager");
        }

        template<typename T>
        std::shared_ptr<ASystem> getSystem() {
            std::string name = typeid(T).name();
            if (_systems.find(name) == _systems.end())
                throw Error::Error("Impossible to get System " + name, "System Manager");
            return _systems[name];
        }

        void changeSignatureFromEntity(Entity id, Signature sign) {
            for (auto const& x : _systems) {
                if ((sign & x.second->getSignature()) == x.second->getSignature())
                    x.second->_entities.insert(id);
                else
                    x.second->_entities.erase(id);
            }
        }

        void updateSystem() {
            std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
            for (auto &x : _systems)
                x.second->update(now);
        }

        void destroyEntity(Entity id) {
            for (auto const & x : _systems)
                x.second->_entities.erase(id);                
        }
	private:
        std::unordered_map<std::string, std::shared_ptr<ASystem>> _systems;
};

#endif /* !SYSTEMMANAGER_HPP_ */
