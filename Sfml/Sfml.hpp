/*
** EPITECH PROJECT, 2019
** R-Type
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <fstream>
#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Component/event.hpp"
#include "Component/boundingBox.hpp"
#include "AssetsFactory.hpp"
#include "Object.hpp"
#include "rendering.hpp"

#define TRANSCOORD(x, y) (x * y / 250)
#define TRANSX(x, y) (TRANSCOORD(x, y))
#define TRANSY(x, y) (TRANSCOORD(x, y))

class Sfml {

    public:
        Sfml();
        ~Sfml();
        void openWindow();
        void closeWindow();
        void updateWindow();
        void drawBox(std::vector<int> pos, std::vector<int> size, int type = 0);
        void drawCircle(std::vector<int> pos, int radius, int type = 0);
        void drawObject(std::string name, std::vector<int> pos);

        void drawText(std::vector<int> pos, int fontSize, std::string str,  const std::string &couleur = "green");
        input getEvent();
        std::string getString(std::vector<int> pos);
        void drawCharacter(std::vector<std::vector<int>> charater, std::vector<int> pos);
        void drawMap(std::map<int, std::vector<int>> map, std::vector<int> pos);
        std::string getName() const {return "sfml";};
        std::vector<int> getPosMenu(const std::string &id) {return _posMenu[id];};
        sf::Clock& getClock() { return _clockObject;};
        sf::Sprite& getSpriteInList(const std::string& id) { return _spriteList[id];};
        void addSpriteInList(const std::string& name, const std::string &path);
        void drawSpriteListe();

        void drawAllObjects() noexcept;

        void updateAllObject(const std::vector<rendering> &objects);

        void loadPlayer(Asset::Type, const std::string &id);
        void loadPlayerDie(const std::string &id);
        void loadPlayerShoot0(const std::string &id);
        void loadPlayerShoot1(const std::string &id);
        void loadBackground();

        void updateParallax();
        void drawBoundingBox(std::vector<boundingBox>);

    private:
        void drawObject(const std::string &name) noexcept;
        void updateObject(const rendering &object);
        void loadMusic();
        void startMusic() noexcept;
        void stopMusic() noexcept;

        sf::RenderWindow _window;
        std::vector<sf::RectangleShape> _box;
        std::vector<sf::CircleShape> _circle;
        sf::Sprite _title;
        std::unordered_map<std::string, sf::Sprite> _backgnd;
        sf::Font _font;
        sf::Event _event;
        std::unordered_map<std::string, sf::Texture> _texture;
        std::vector<sf::Sprite> _enemy;
        std::vector<sf::Sprite> _wall;
        std::vector<sf::Sprite> _objet;
        std::unordered_map<std::string, std::unique_ptr<Asset::IAsset>> _objects;
        Asset::AssetsFactory _factory;
        std::vector<sf::Sprite> _character;
        std::map<std::string, std::vector<int>> _posMenu;
        std::map<std::string, std::vector<sf::Sprite>> _Objmap;
        void drawObjMap(const std::string &type, int id, std::vector<int> pos);
        sf::Clock _clock;
        sf::Clock _clockObject;
        sf::Clock _clockParallax;
        std::map<std::string, sf::Sprite> _spriteList;
        std::string _ressourcesPath;
        sf::Music _music;
};

#endif /* !SFML_HPP_ */
