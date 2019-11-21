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
			if (_entityToIndex.find(id) != _entityToIndex.end()) {
				_entityToIndex[id] = _size;
				_indexToEntity[_size] = id;
				_component[_size] = component;
				_size++;
			} else
				throw std::exception();			
		}
		void remove(Entity id) {
			if (_entityToIndex.find(id) != _entityToIndex.end()) {
				std::size_t removedIndex = _entityToIndex[id];
				_size--;
				_component[_size] = _component[removedIndex];
				Entity idLast = _indexToEntity[_size];
				_entityToIndex[idLast] = removedIndex;
				_indexToEntity[removedIndex] = idLast;
				_entityToIndex.erase(id);
				_indexToEntity.erase(_size);
			}
		}
		T& getComponent(Entity id) {
			T& result;
			if (_entityToIndex.find(id) != _entityToIndex.end()) {
				result = _component[_entityToIndex[id]];
			} else
				throw std::exception();	
			return result;
		}
		void destroyEntity(Entity id) override {
			remove(id);
		}
	private:
		std::array<T, MAX_ENTITY> _component;
		std::unordered_map<Entity, std::size_t> _entityToIndex;
		std::unordered_map<std::size_t, Entity> _indexToEntity;
		std::size_t _size;
};

#endif /* !COMPONENTARRAY_HPP_ */