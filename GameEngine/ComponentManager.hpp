/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include <unordered_map>
#include <memory>
#include "ECS.hpp"
#include "IComponentArray.hpp"
#include "ComponentArray.hpp"

using namespace ECS;

class ComponentManager {
	public:
		ComponentManager() {};
		~ComponentManager() {};

		template<typename T>
		void insertComponent() {
			std::string name = typeid(T).name();
			if (_component.find(name) == _component.end()) {
				_componentID.insert({name, _nextID});
				_component.insert({name, std::make_shared<ComponentArray<T>>()});
				_nextID++;
			} else
				throw std::exception();
		}

		template<typename T>
		ComponentID getComponentID() {
			std::string name = typeid(T).name();
			if (_component.find(name) == _component.end())
				throw std::exception();
			return _componentID[name];
		}

		template<typename T>
		void addToArray(Entity id, T component) { GetComponentArray<T>()->insert(id, component);}

		template<typename T>
		void removeToArray(Entity id) { GetComponentArray<T>()->remove(id);}

		template<typename T>
		T& getToArray(Entity id) { return GetComponentArray<T>()->getComponent(id);}

		template<typename T>
		std::shared_ptr<ComponentArray<T>> GetComponentArray()
		{
			std::string name = typeid(T).name();
			if (_component.find(name) == _component.end())
				throw std::exception();
			return std::static_pointer_cast<ComponentArray<T>>(_component[name]);
		}

		void destroyEntity(Entity id) {
			for (auto const& x : _component)
				x.second->destroyEntity(id);
		}
	private:
        std::unordered_map<std::string, std::shared_ptr<IComponentArray>>  _component;
        std::unordered_map<std::string, ComponentID>  _componentID;
        ComponentID _nextID;		
};

#endif /* !COMPONENTMANAGER_HPP_ */
