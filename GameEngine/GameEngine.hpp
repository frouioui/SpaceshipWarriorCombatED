/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include "ECS.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "ComponentManager.hpp"
#include "Error.hpp"

class GameEngine {
	public:
		GameEngine();
		~GameEngine();
                Entity createEntity();
                void destroyEntity(Entity id);

                template<typename T>
                void insertSystem(std::shared_ptr<GameEngine>& eg) { _systems->insertSystem<T>(eg);};

                template<typename T>
                void insertComponent() { _components->insertComponent<T>();};

                template<typename T>
                void removeComponent(Entity id) { _components->removeToArray<T>(id);};

                template<typename T>
                void addComponent(Entity id, T component) { _components->addToArray<T>(id, component);};

                template<typename T>
                T& getComponent(Entity id) const { return _components->getToArray<T>(id);};

                template<typename T>
                ComponentID getComponentID() const { return _components->getComponentID<T>();};

                template<typename T>
                std::shared_ptr<ASystem> getSystem() const {return _systems->getSystem<T>();};

                void setEntitySystem(Entity id, Signature sign);

                void updateSystem();

                template<typename T>
                std::shared_ptr<ComponentArray<T>> getComponentArray() const {return _components->GetComponentArray<T>();};

                template<typename T>
                bool isEntityHave(Entity id) {
                        Signature result;
                        auto x = _entities->getSignature(id);
                        result.set(getComponentID<T>());
                        std::cout << ((x & result) == result) << std::endl;
                        if ((x & result) == result)
                                return true;
                        return false;
                }
        private:
                std::unique_ptr<EntityManager> _entities;
                std::unique_ptr<SystemManager> _systems;
                std::unique_ptr<ComponentManager> _components;
};

#endif /* !GAMEENGINE_HPP_ */
