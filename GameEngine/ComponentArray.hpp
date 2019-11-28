/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** ComponentArray
*/

#ifndef COMPONENTARRAY_HPP_
#define COMPONENTARRAY_HPP_

#include <array>
#include <unordered_map>
#include "IComponentArray.hpp"

using namespace ECS;

template<typename T>
class ComponentArray : public IComponentArray {
	public:
		ComponentArray() : _component(), _entityToIndex(), _indexToEntity(), _size(0){};
		~ComponentArray() {};
		void insert(Entity id, T component) {
			if (_entityToIndex.find(id) == _entityToIndex.end()) {
				_entityToIndex[id] = _size;
				_indexToEntity[_size] = id;
				_component[_size] = component;
				_size++;
			} else
				throw Error::Error("Impossible to insert Component", "Compnent Array");			
		}
		void remove(Entity id) {
			if (_entityToIndex.find(id) != _entityToIndex.end()) {
				_size--;
				std::size_t removedIndex = _entityToIndex[id];
				_component[removedIndex] = _component[_size];
				Entity idLast = _indexToEntity[_size];
				_entityToIndex[idLast] = removedIndex;
				_indexToEntity[removedIndex] = idLast;
				_entityToIndex.erase(id);
				_indexToEntity.erase(_size);
			}
		}
		T& getComponent(Entity id) {
			if (_entityToIndex.find(id) == _entityToIndex.end())
				throw Error::Error(std::string("Impossible to get Component ") + std::string(typeid(T).name()), "Compnent Array");
			return _component[_entityToIndex[id]];
		}
		void destroyEntity(Entity id) override {
			remove(id);
		}
		std::vector<T> listedComponent()
		{
			std::vector<T> result;
			for (std::size_t i = 0; i < _size; i++)
				result.push_back(_component[i]);
			return result;
		}
	private:
		std::array<T, MAX_ENTITY> _component;
		std::unordered_map<Entity, std::size_t> _entityToIndex;
		std::unordered_map<std::size_t, Entity> _indexToEntity;
		std::size_t _size;
};

#endif /* !COMPONENTARRAY_HPP_ */
