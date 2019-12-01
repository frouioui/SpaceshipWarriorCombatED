/*
** EPITECH PROJECT, 2019
** R-Type

** File description:
** Sfml
*/

#include <iostream>
#include "Sfml.hpp"
#include "Error.hpp"

Sfml::Sfml() : _window(), _box(), _circle(), _title(), _event(),
_texture(), _enemy(), _wall(), _objet(), _objects(), _character(), _posMenu(), _Objmap(), _clockObject(),
_clockParallax(), _spriteList(), _ressourcesPath()
{
    std::string projectPath;
    // const size_t last_slash_idx = std::string(std::getenv("PWD")).rfind('/');

    // if (std::string::npos != last_slash_idx) {
    //     projectPath = std::string(std::getenv("PWD")).substr(0, last_slash_idx);
    // }
        projectPath = std::string(std::getenv("PWD"));
    _ressourcesPath = projectPath + "/ressources/";
    sf::RectangleShape box1 = sf::RectangleShape();
    box1.setOutlineThickness(1);
    box1.setOutlineColor(sf::Color::Green);
    box1.setFillColor(sf::Color::Transparent);
    _box.push_back(box1);
    box1.setOutlineThickness(1);
    box1.setOutlineColor(sf::Color::Red);
    box1.setFillColor(sf::Color::Transparent);
    _box.push_back(box1);
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::Yellow);
    circle.setOutlineThickness(1);
    _circle.push_back(circle);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineColor(sf::Color::Red);
    circle.setOutlineThickness(1);
    _circle.push_back(circle);

    loadBackground();
    try {
        loadMusic();
    } catch (Error::Sfml::SfmlError &e) {
        std::cerr << e.what() << e.where() << std::endl;
    }
    if (!_font.loadFromFile(_ressourcesPath + "CaviarDreams.ttf"))
    	throw std::exception();
}

Sfml::~Sfml()
{
    stopMusic();
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

void Sfml::loadPlayer(Asset::Type type, const std::string &id)
{
    switch (type)
    {
    case Asset::PLAYER0:
        _objects[id] = _factory.createAsset(Asset::PLAYER0, _ressourcesPath);
        break;
    case Asset::PLAYER1:
        _objects[id] = _factory.createAsset(Asset::PLAYER1, _ressourcesPath);
        break;
    case Asset::PLAYER2:
        _objects[id] = _factory.createAsset(Asset::PLAYER2, _ressourcesPath);
        break;
    case Asset::PLAYER3:
        _objects[id] = _factory.createAsset(Asset::PLAYER3, _ressourcesPath);
        break;
    default:
        break;
    }
}

void Sfml::loadPlayerDie(const std::string &id)
{
    _objects[id] = _factory.createAsset(Asset::PLAYERDIE, _ressourcesPath);
}

void Sfml::loadPlayerShoot0(const std::string &id)
{
    _objects[id] = _factory.createAsset(Asset::PLAYERSHOOT0, _ressourcesPath);
}

void Sfml::loadPlayerShoot1(const std::string &id)
{
    _objects[id] = _factory.createAsset(Asset::PLAYERSHOOT1, _ressourcesPath);
}

void Sfml::loadEnemy(const std::string &id, const std::string &path, int height, int width)
{
    _objects[id] = _factory.createAsset(Asset::ENNEMY0, path, height, width);
}

void Sfml::drawBox(std::vector<int> pos, std::vector<int> size, int type)
{
    sf::RectangleShape box = sf::RectangleShape(_box[type]);
    box.setPosition((float)TRANSX(pos[1], (int)_window.getSize().x), (float)TRANSY(pos[0], (int)_window.getSize().y));
    box.setSize({(float)TRANSX(size[1], (int)_window.getSize().x), (float)TRANSY(size[0], (int)_window.getSize().y)});
    _window.draw(box);
}

void Sfml::drawCircle(std::vector<int> pos, int radius, int type)
{
    sf::CircleShape box = sf::CircleShape(_circle[type]);
    box.setPosition((float)TRANSX(pos[1], (int)_window.getSize().x), (float)TRANSY(pos[0], (int)_window.getSize().y));
    box.setRadius((float)TRANSY(radius, (int)_window.getSize().y));
    _window.draw(box);
}

void Sfml::loadBackground()
{
    sf::Texture texture;
    std::string texturePath1 = _ressourcesPath + "parallax1.jpg";
    std::string texturePath2 = _ressourcesPath + "parallax2.jpg";

    if (!texture.loadFromFile(texturePath1)) {
        throw Error::Sfml::SfmlError("Failed to load parallax1.jpg", "Sfml::loadBackground");
    }
    _texture[texturePath1] = sf::Texture(texture);
    _backgnd["parallax1"].setTexture(_texture[texturePath1]);
    if (!texture.loadFromFile(texturePath2)) {
        throw Error::Sfml::SfmlError("Failed to load parallax2.jpg", "Sfml::loadBackground");
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

void Sfml::drawAllObjects() noexcept
{
    for (auto it = _objects.begin(); it != _objects.end(); it++) {
        _window.draw(it->second->getSprite());
    }
}

void Sfml::drawObject(const std::string &name) noexcept
{
    _window.draw(_objects[name]->getSprite());
}

void Sfml::updateAllObject(const std::vector<rendering> &objects)
{
    _objects.clear();
    for (auto it = objects.begin(); it != objects.end(); it++) {
        updateObject(*it);
    }
}

void Sfml::updateObject(const rendering &object)
{
    switch (object.type)
    {
    case Asset::PLAYER0:
        loadPlayer(object.type, object.id);
        break;
    case Asset::PLAYER1:
        loadPlayer(object.type, object.id);
        break;
    case Asset::PLAYER2:
        loadPlayer(object.type, object.id);
        break;
    case Asset::PLAYER3:
        loadPlayer(object.type, object.id);
        break;
    case Asset::PLAYERDIE:
        loadPlayerDie(object.id);
        break;
    case Asset::PLAYERSHOOT0:
        loadPlayerShoot0(object.id);
        break;
    case Asset::PLAYERSHOOT1:
        loadPlayerShoot0(object.id);
        break;
    case Asset::ENNEMY0:
        // loadEnemy(object.id, object.path, object.height, object.width);
        break;
    default:
        break;
    }
    auto it = _objects.find(object.id);

    if (it == _objects.end())
        return
    _objects[object.id]->updateSprite((float)TRANSCOORD(object.pos[1], (int)_window.getSize().x),
        (float)TRANSCOORD(object.pos[0], (int)_window.getSize().y));
    _objects[object.id]->updateSprite(object.pos[0], object.pos[1]);
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

std::vector<input> Sfml::getEvent()
{
    std::vector<input> result;
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Escape)
                result.push_back(input::ECHAP);
            if (_event.key.code == sf::Keyboard::Up)
                result.push_back(input::KEYUP);
            if (_event.key.code == sf::Keyboard::Right)
                result.push_back(input::KEYRIGTH);
            if (_event.key.code == sf::Keyboard::Left)
                result.push_back(input::KEYLEFT);
            if (_event.key.code == sf::Keyboard::Down)
                result.push_back(input::KEYDOWN);
            if (_event.key.code == sf::Keyboard::Enter)
                result.push_back(input::ENTER);
            if (_event.key.code == sf::Keyboard::Space)
                result.push_back(input::SPACE);
            if (_event.key.code == sf::Keyboard::L)
                result.push_back(input::CHEAT5);
            if (_event.key.code == sf::Keyboard::Y)
                result.push_back(input::CHEAT2);
            if (_event.key.code == sf::Keyboard::C)
                result.push_back(input::CHEAT1);
            if (_event.key.code == sf::Keyboard::I)
                result.push_back(input::CHEAT4);
            if (_event.key.code == sf::Keyboard::R)
                result.push_back(input::CHEAT3);
            if (_event.key.code == sf::Keyboard::W)
                result.push_back(input::BUTTON1);
            if (_event.key.code == sf::Keyboard::X)
                result.push_back(input::BUTTON2);
        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            result.push_back(input::CLICK_LEFT);
        }
        if (_event.type == sf::Event::Closed)
            result.push_back(input::CLOSE);
    }
    return result;
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
    static float elapsed = time.asMicroseconds();

	if (elapsed < 10000) {
	    elapsed = _clock.getElapsedTime().asMicroseconds();
		return;
	}
	_window.display();
	_window.clear();
	_clock.restart();
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

void Sfml::drawBoundingBox(std::vector<boundingBox> list)
{
	for (auto x : list) {
		if (x.type == SQUARE) {
			drawBox({x.pos[UPPERLEFT].first, x.pos[UPPERLEFT].second},
					{x.pos[LOWERLEFT].first - x.pos[UPPERLEFT].first,
					x.pos[UPPERRIGHT].second - x.pos[UPPERLEFT].second
					});
		}
        if (x.type == CIRCLE) {
			drawCircle({x.pos[0].first, x.pos[0].second}, x.pos[1].first);
		}
	}
}

void Sfml::loadMusic()
{
    if (!_music.openFromFile(_ressourcesPath + "r-type_music.ogg"))
        throw Error::Sfml::SfmlError("Failed to load music", "Sfml::loadMusic");
    _music.setLoop(true);
    startMusic();
}

void Sfml::startMusic() noexcept
{
    _music.play();
}

void Sfml::stopMusic() noexcept
{
    _music.stop();
}