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
#include "Sfml.hpp"

class GameEngine {
	public:
		GameEngine();
		~GameEngine();
                Entity createEntity();
                void destroyEntity(Entity id);

                template<typename T>
                void insertSystem() { _systems->insertSystem<T>();};

                template<typename T>
                void insertComponent() { _components->insertComponent<T>();};

                template<typename T>
                void removeComponent(Entity id) { _components->removeToArray<T>(id);};

                template<typename T>
                void addComponent(Entity id) { _components->addToArray<T>(id);};

                template<typename T>
                T& getComponent(Entity id) { return _components->getToArray<T>(id);};

                template<typename T>
                ComponentID getComponentID() { return _components->getComponentID<T>();};

                template<typename T>
                std::shared_ptr<ASystem> getSystem() {return _systems->getSystem<T>();};

                std::unique_ptr<Sfml>& getSfml() { return _sfml;};
        private:
                std::unique_ptr<EntityManager> _entities;
                std::unique_ptr<SystemManager> _systems;
                std::unique_ptr<ComponentManager> _components;
                std::unique_ptr<Sfml> _sfml;
};

#endif /* !GAMEENGINE_HPP_ */
