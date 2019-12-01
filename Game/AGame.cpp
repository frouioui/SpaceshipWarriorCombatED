/*
** EPITECH PROJECT, 2019
** SpaceshipWarriorCombatED
** File description:
** AGame
*/

#include "AGame.hpp"


AGame::AGame() : _loader(), _event(), _enemy(), _objet(), _wall(), _player(), _stage(0)
{
    gameEngine = std::make_shared<GameEngine>();
}

AGame::~AGame()
{
}


void AGame::addEvent(Event input)
{
    _event.push_back(input);
}

std::vector<rendering> AGame::getRendering()
{
    return gameEngine->getComponentArray<rendering>()->listedComponent();
}

std::vector<boundingBox> AGame::getBoundingBox()
{
    return gameEngine->getComponentArray<boundingBox>()->listedComponent();
}


void AGame::loadEnnemy()
{
    std::string projectPath;
    const size_t last_slash_idx = std::string(std::getenv("PWD")).rfind('/');

    if (std::string::npos != last_slash_idx) {
        projectPath = std::string(std::getenv("PWD")).substr(0, last_slash_idx);
    }
    std::vector<std::string> pathname;
    DIR *dir;
    struct dirent *ent;
    std::string enemyObject = projectPath + "/Game/Enemy/lib/";
    if ((dir = opendir(enemyObject.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            std::string result = ent->d_name;
            if (result.find(".so") != std::string::npos)
                pathname.push_back(result);
        }
        closedir(dir);
    } else
        throw Error::Error("Impossible to open directory");
    for (auto x : pathname) {
        _lib.push_back(_loader.loadLib(enemyObject + x));
        _enemy.push_back(_loader.getInstance<IObjet>(_lib.back(), "Enemy"));
        _enemy.back()->setGameEngine(gameEngine);
    }
}

void AGame::loadRandomObject()
{
    std::string projectPath;
    const size_t last_slash_idx = std::string(std::getenv("PWD")).rfind('/');

    if (std::string::npos != last_slash_idx) {
        projectPath = std::string(std::getenv("PWD")).substr(0, last_slash_idx);
    }
    std::vector<std::string> pathname;
    DIR *dir;
    struct dirent *ent;
    std::string randomObject = projectPath + "/Game/Object/Random/lib/";
    if ((dir = opendir(randomObject.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            std::string result = ent->d_name;
            if (result.find(".so") != std::string::npos)
                pathname.push_back(result);
        }
        closedir(dir);
    } else
        throw Error::Error("Impossible to open directory");
    for (auto x : pathname) {
        _lib.push_back(_loader.loadLib(randomObject + x));
        _objet.push_back(_loader.getInstance<IObjet>(_lib.back(), "Random"));
        _objet.back()->setGameEngine(gameEngine);
    }
}

void AGame::loadWallObject()
{
    std::string projectPath;
    const size_t last_slash_idx = std::string(std::getenv("PWD")).rfind('/');

    if (std::string::npos != last_slash_idx) {
        projectPath = std::string(std::getenv("PWD")).substr(0, last_slash_idx);
    }
    std::vector<std::string> pathname;
    DIR *dir;
    struct dirent *ent;
    std::string WallObject = projectPath + "/Game/Object/Wall/lib/";


    if ((dir = opendir(WallObject.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            std::string result = ent->d_name;
            #if defined(__APPLE__)
                if (result.find(".dylib") != std::string::npos)
                pathname.push_back(result);
            #else
                if (result.find(".so") != std::string::npos)
                pathname.push_back(result);
            #endif
        }
        closedir(dir);
    } else
        throw Error::Error("Impossible to open directory");
    for (auto x : pathname) {
        _lib.push_back(_loader.loadLib(WallObject + x));
        _wall.push_back(_loader.getInstance<IObjet>(_lib.back(), "Wall"));
        _wall.back()->setGameEngine(gameEngine);
    }
}

void AGame::deletePlayer(int id)
{

}

void AGame::addPlayer()
{

}
