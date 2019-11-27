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
                T& getComponent(Entity id) { return _components->getToArray<T>(id);};

                template<typename T>
                ComponentID getComponentID() { return _components->getComponentID<T>();};

                template<typename T>
                std::shared_ptr<ASystem> getSystem() {return _systems->getSystem<T>();};

                void setEntitySystem(Entity id, Signature sign) { _systems->changeSignatureFromEntity(id, sign);};

                void updateSystem() { _systems->updateSystem();};

                template<typename T>
                std::shared_ptr<ComponentArray<T>> getComponentArray() {return _components->GetComponentArray<T>();};
        private:
                std::unique_ptr<EntityManager> _entities;
                std::unique_ptr<SystemManager> _systems;
                std::unique_ptr<ComponentManager> _components;
};

#endif /* !GAMEENGINE_HPP_ */
