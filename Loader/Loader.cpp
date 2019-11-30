/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** Loader
*/

#include "Loader.hpp"

Loader::Loader()
{
}

Loader::~Loader()
{
}

void *Loader::loadLib(const std::string &path)
{
    void *lib = dlopen(path.c_str(), RTLD_LOCAL | RTLD_LAZY);

    if (!lib) {
        std::cerr << dlerror() << std::endl;
        throw std::exception();
    }
    return lib;
}

void Loader::closeLib(void *lib)
{
    if (dlclose(lib) != 0)
		std::cerr << dlerror() << std::endl;
}