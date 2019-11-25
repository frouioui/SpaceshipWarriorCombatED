/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Sfml
*/

#include <iostream>
#include "Sfml.hpp"

Sfml::Sfml() : _window(), _box(), _title(), _event(),
_texture(), _enemy(), _wall(), _objet(), _character(), _posMenu(), _Objmap(), _clock()
{
    std::string projectPath;
    const size_t last_slash_idx = std::string(std::getenv("PWD")).rfind('/');

    if (std::string::npos != last_slash_idx) {
        projectPath = std::string(std::getenv("PWD")).substr(0, last_slash_idx);
    }
        // projectPath = std::string(std::getenv("PWD"));
    _assetsPath = projectPath + "/ressources/";
    // sf::RectangleShape box1 = sf::RectangleShape();
    // box1.setOutlineThickness(1);
    // box1.setOutlineColor(sf::Color::Green);
    // box1.setFillColor(sf::Color::Transparent);
    // _box.push_back(box1);
    // TODO: path to global
    // if (!_font.loadFromFile("../../ressources/CaviarDreams.ttf"))
    // 	throw std::exception();

    /* POSITION MENU */

    // _posMenu.emplace("posTitle", std::vector<int>({0,17}));
    // _posMenu.emplace("posName", std::vector<int>({63, 33}));
    // _posMenu.emplace("posBoxname", std::vector<int>({60, 29}));
    // _posMenu.emplace("posUndertitle", std::vector<int>({33,19}));
    // _posMenu.emplace("sizeBoxname", std::vector<int>({10,40}));
    // _posMenu.emplace("posQuestion", std::vector<int>({55, 43}));
    // _posMenu.emplace("posBoxGame", std::vector<int>({40, 10}));
    // _posMenu.emplace("sizeBoxGame", std::vector<int>({40, 30}));
    // _posMenu.emplace("posGame", std::vector<int>({45, 15}));
    // _posMenu.emplace("posExit", std::vector<int>({85, 47}));
    // _posMenu.emplace("posBoxLib", std::vector<int>({40, 60}));
    // _posMenu.emplace("sizeBoxLib", std::vector<int>({40, 30}));
    // _posMenu.emplace("posLib", std::vector<int>({45, 65}));
    // _posMenu.emplace("posTitleScore", std::vector<int>({65, 85}));
    // _posMenu.emplace("posScore", std::vector<int>({75, 85}));
    // _posMenu.emplace("posBoxScore", std::vector<int>({74, 84}));
    // _posMenu.emplace("sizeBoxScore", std::vector<int>({5, 10}));
    // _posMenu.emplace("posMap", std::vector<int>({40, 3}));
}

Sfml::~Sfml()
{
}

void Sfml::openWindow()
{
    _window.create(sf::VideoMode(1920, 1200), "SpaceshipWarriorCombatED");
    _window.setFramerateLimit(60);

}

void Sfml::closeWindow()
{
    _window.close();
}

void Sfml::drawBox(std::vector<int> pos, std::vector<int> size, int type)
{
    sf::RectangleShape box = sf::RectangleShape(_box[type]);
    box.setPosition((float)TRANSX(pos[1], (int)_window.getSize().x), (float)TRANSY(pos[0], (int)_window.getSize().y));
    box.setSize({(float)TRANSX(size[1], (int)_window.getSize().x), (float)TRANSY(size[0], (int)_window.getSize().y)});
    _window.draw(box);
}

void Sfml::loadBackground()
{
    sf::Texture texture;
    std::string texturePath1 = _assetsPath + "parallax1.jpg";
    std::string texturePath2 = _assetsPath + "parallax2.jpg";

    if (!texture.loadFromFile(texturePath1)) {
        throw std::exception();
    }
    _texture[texturePath1] = sf::Texture(texture);
    _backgnd["parallax1"].setTexture(_texture[texturePath1]);
    if (!texture.loadFromFile(texturePath2)) {
        throw std::exception();
    }
    _texture[texturePath2] = sf::Texture(texture);
    _backgnd["parallax2"].setTexture(_texture[texturePath2]);
}

void Sfml::updateParallax()
{
    static sf::Vector2f backgnd1Pos(0, 0);
    static sf::Vector2f backgnd2Pos(5190, 0);

    backgnd1Pos.x -= 1;
    backgnd2Pos.x -= 1;
    _backgnd["parallax1"].setPosition(backgnd1Pos);
    _backgnd["parallax2"].setPosition(backgnd2Pos);
    if (backgnd1Pos.x == -5190)
        backgnd1Pos.x = 5190;
    if (backgnd2Pos.x == -5190)
        backgnd2Pos.x = 5190;
    _window.draw(_backgnd["parallax1"]);
    _window.draw(_backgnd["parallax2"]);
}

void Sfml::drawObject(std::string name, std::vector<int> pos)
{
    // (void)pos;
    // (void)name;
    // sf::Sprite sprite;
    // sf::Texture texture;
    std::string path = _assetsPath + "r-typesheet" + name + ".gif";
    // if(texture.loadFromFile("./lib/sfml/" + name + ".png")) {
    //     sprite.setTexture(texture);
    //     sprite.setPosition((float)TRANSCOORD(pos[1], (int)_window.getSize().x), (float)TRANSCOORD(pos[0], (int)_window.getSize().y));
    //     _window.draw(sprite);
    // }
    // else
    //     throw std::exception();
    _objet[path].setPosition(1000, 100);
    _window.draw(_objet[path]);
}

void Sfml::drawText(std::vector<int> pos, int fontSize, std::string str,  const std::string &couleur)
{
    (void)couleur;
    (void)pos;
    (void)fontSize;
    (void)str;
    static sf::Text *text = new sf::Text();
    sf::Color color(9, 106, 9);
    text->setFont(_font);
    text->setString(str);
    text->setCharacterSize(fontSize);
    if (couleur =="green")
        text->setFillColor(sf::Color::Green);
    if (couleur == "selected")
        text->setFillColor(color);
    if (couleur =="yellow")
        text->setFillColor(sf::Color::Yellow);
    text->setPosition((float)TRANSCOORD(pos[1], (int)_window.getSize().x), (float)TRANSCOORD(pos[0], (int)_window.getSize().y));
    _window.draw(*text);
}


input Sfml::getEvent()
{
    // sf::Event event;

    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Escape)
                return input::ECHAP;
            if (_event.key.code == sf::Keyboard::Up)
                return input::KEYUP;
            if (_event.key.code == sf::Keyboard::Right)
                return input::KEYRIGTH;
            if (_event.key.code == sf::Keyboard::Left)
                return input::KEYLEFT;
            if (_event.key.code == sf::Keyboard::Down)
                return input::KEYDOWN;
            if (_event.key.code == sf::Keyboard::Enter)
                return input::ENTER;
            if (_event.key.code == sf::Keyboard::Space)
                return input::SPACE;
            if (_event.key.code == sf::Keyboard::L)
                return input::CHEAT5;
            if (_event.key.code == sf::Keyboard::Y)
                return input::CHEAT2;
            if (_event.key.code == sf::Keyboard::C)
                return input::CHEAT1;
            if (_event.key.code == sf::Keyboard::I)
                return input::CHEAT4;
            if (_event.key.code == sf::Keyboard::R)
                return input::CHEAT3;
            if (_event.key.code == sf::Keyboard::W)
                return input::BUTTON1;
            if (_event.key.code == sf::Keyboard::X)
                return input::BUTTON2;
        }
        if (_event.type == sf::Event::Closed)
            return input::CLOSE;
        return input::NOTHING;
    }
    return input::NOTHING;
}

std::string Sfml::getString(std::vector<int> pos)
{
    (void)pos;
    std::string str = "";
    sf::Event event;

    while (1) {
        _window.display();
        _window.waitEvent(event);
        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128)
            {
                str += static_cast<char>(event.text.unicode);
                drawText(pos, 30, str);
            }
        }
        if (event.type == sf::Event::KeyPressed)
            if (event.key.code == sf::Keyboard::Enter && str != "")
                break;
    }
    return str;
}

void Sfml::drawCharacter(std::vector<std::vector<int>> charater, std::vector<int> pos)
{
    float x0 = TRANSCOORD(pos[1], (int)_window.getSize().x);
    float y0 = TRANSCOORD(pos[0], (int)_window.getSize().y);

    for(auto x : charater) {
        sf::Sprite sprite(_character.front());
        sprite.setPosition({x[1] * 19 + x0, x[0] * 19 + y0});
        _window.draw(sprite);
    }
}

void Sfml::updateWindow()
{
    sf::Time time = _clock.getElapsedTime();
    float elapsed = time.asMicroseconds();
    std::vector<int> pos;

    pos.push_back(1000);
    pos.push_back(1000);
    while (_window.isOpen()) {
        if (getEvent() == input::CLOSE)
            closeWindow();
        while (elapsed < 100000) {
            elapsed = _clock.getElapsedTime().asMicroseconds();
        }
        _window.clear();
        updateParallax();
        drawObject("1", pos);
        _window.display();
        _clock.restart();
    }
}

void Sfml::loadAsset()
{
//     _character.clear();
//     _enemy.clear();
    // _wall.clear();
    // _Objmap.clear();
    // _texture.clear();

    sf::Texture texture;
    sf::Sprite sprite;
    std::string path;
    int i = 1;

    _objet.clear();
    while (std::ifstream(_assetsPath + "r-typesheet" + std::to_string(i) + ".gif")) {
        path = _assetsPath + "r-typesheet" + std::to_string(i) + ".gif";
        if (!texture.loadFromFile(path))
            throw std::exception();
        _texture[path] = sf::Texture(texture);
        sprite.setTexture(_texture[path]);
        // sprite.setScale(0.5f, 0.5f);
        _objet[path] = sf::Sprite(sprite);
        i++;
    }
    // i = 0;
    // if (_character.size() > 0)
    //     _Objmap.emplace("character", _character);
    // while (std::ifstream("./lib/sfml/" + name + "/objet" + std::to_string(i) + ".png")) {
    //     texture.loadFromFile("./lib/sfml/" + name + "/objet" + std::to_string(i) + ".png");
    //     _texture.push_back(sf::Texture(texture));
    //     sprite.setTexture(_texture.back());
    //     sprite.setScale(0.5f, 0.5f);
    //     _objet.push_back(sf::Sprite(sprite));
    //     i++;
    // }
    // i = 0;
    // if (_objet.size() > 0)
    //     _Objmap.emplace("objet", _objet);
    // while (std::ifstream("./lib/sfml/" + name + "/wall" + std::to_string(i) + ".png")) {
    //     texture.loadFromFile("./lib/sfml/" + name + "/wall" + std::to_string(i) + ".png");
    //     _texture.push_back(sf::Texture(texture));
    //     sprite.setTexture(_texture.back());
    //     sprite.setScale(0.5f, 0.5f);
    //     _wall.push_back(sf::Sprite(sprite));
    //     i++;
    // }
    // i = 0;
    // if (_wall.size() > 0)
    //     _Objmap.emplace("wall", _wall);
    // while (std::ifstream("./lib/sfml/" + name + "/enemy" + std::to_string(i) + ".png")) {
    //     texture.loadFromFile("./lib/sfml/" + name + "/enemy" + std::to_string(i) + ".png");
    //     _texture.push_back(sf::Texture(texture));
    //     sprite.setTexture(_texture.back());
    //     sprite.setScale(0.5f, 0.5f);
    //     _enemy.push_back(sf::Sprite(sprite));
    //     i++;
    // }
    // if (_enemy.size() > 0)
    //     _Objmap.emplace("enemy", _enemy);
}

void Sfml::drawObjMap(const std::string &type, int id, std::vector<int> pos)
{
    if (_Objmap.find(type) != _Objmap.end()) {
        sf::Sprite sprite(_Objmap[type][id]);
        sprite.setPosition({(float)pos[1], (float)pos[0]});
        _window.draw(sprite);
    }
}

void Sfml::drawMap(std::map<int, std::vector<int>> map, std::vector<int> pos)
{
    float x0 = TRANSCOORD(pos[1], (int)_window.getSize().x);
    float y0 = TRANSCOORD(pos[0], (int)_window.getSize().y);
    int x = 0;
    int y = 0;

    for (auto m : map)
    {
        x = 0;
        for (auto i : m.second) {
            if (i == 1)
                drawObjMap("wall", 0, {y * 19 + (int)y0,x * 19 + (int)x0});
            if (i >= 10)
                drawObjMap("objet", i - 10, {y * 19 + (int)y0, x * 19 + (int)x0});
            if (i < 0)
                drawObjMap("enemy" ,-i - 1, {y * 19 + (int)y0, x * 19 + (int)x0});
            x++;
        }
        y++;
    }
}

void Sfml::addSpriteInList(const std::string& name, const std::string &path)
{
    sf::Sprite _obj;
    sf::Sprite sprite;
    sf::Texture texture;
    if(texture.loadFromFile(path)) {
        sprite.setTexture(texture);
        _spriteList[name] = sprite;
    }
    else
        throw std::exception();
}

void Sfml::drawSpriteListe()
{
    for (auto x:_spriteList) {
        _window.draw(x.second);
    }
}