/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Component/event.hpp"


#define TRANSCOORD(x, y) (x * y / 100)
#define TRANSX(x, y) (TRANSCOORD(x, y / 8) * 8)
#define TRANSY(x, y) (TRANSCOORD(x, y / 16) * 16)

class Sfml {
	public:
        Sfml();
        ~Sfml();
        void openWindow();
        void closeWindow();
        void updateWindow();
        void drawBox(std::vector<int> pos, std::vector<int> size, int type = 0);
        void drawObject(std::string name, std::vector<int> pos);
        void drawText(std::vector<int> pos, int fontSize, std::string str,  const std::string &couleur = "green");
        input getEvent();
        std::string getString(std::vector<int> pos);
		void loadAsset(const std::string &name);
		void drawCharacter(std::vector<std::vector<int>> charater, std::vector<int> pos);
		void drawMap(std::map<int, std::vector<int>> map, std::vector<int> pos);
		std::string getName() const {return "sfml";};
	    std::vector<int> getPosMenu(const std::string &id) {return _posMenu[id];};
        sf::Clock& getClock() { return _clock;};
        sf::Sprite& getSpriteInList(const std::string& id) { return _spriteList[id];};
        void addSpriteInList(const std::string& name, const std::string &path);
        void drawSpriteListe();
	private:
        sf::RenderWindow _window;
        std::vector<sf::RectangleShape> _box;
        sf::Sprite _title;
        sf::Font _font;
        sf::Event _event;
		std::vector<sf::Texture> _texture;
        std::vector<sf::Sprite> _enemy;
        std::vector<sf::Sprite> _wall;
        std::vector<sf::Sprite> _objet;
        std::vector<sf::Sprite> _character;
		std::map<std::string, std::vector<int>> _posMenu;
		std::map<std::string, std::vector<sf::Sprite>> _Objmap;
		void drawObjMap(const std::string &type, int id, std::vector<int> pos);
        sf::Clock _clock;
        std::map<std::string, sf::Sprite> _spriteList;
};

#endif /* !SFML_HPP_ */



