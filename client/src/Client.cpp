#include <iostream>
#include "Client.hpp"
#include "boundingBox.hpp"
#include "Packet.hpp"
#include "Basic.hpp"

Client::Client(UDPInfo &info) : _network(info)
{
    _running = true;
}

Client::Client(UDPInfo &info, const std::string &server_ip, short server_port) : _network(info, server_ip, server_port)
{
    _running = true;
}

Client::~Client()
{
}

int Client::selectRoomMenu()
{
    input counter = input::NOTHING;
    bool done = false;
    int roomId = 1;

    std::cout << "launching menu" << std::endl;
    std::vector<int> posText = {10, 50};
    std::vector<int> posText1 = {55, 90};
    std::vector<int> posText2 = {80, 90};
    std::vector<int> posText3 = {105, 90};
    std::vector<int> posText4 = {130, 90};
    std::vector<int> posBtn1 = {50, 85};
    std::vector<int> posBtn2 = {75, 85};
    std::vector<int> posBtn3 = {100, 85};
    std::vector<int> posBtn4 = {125, 85};
    std::vector<int> sizeBtn1 = {20, 85};
    std::vector<int> sizeBtn2 = {20, 85};
    std::vector<int> sizeBtn3 = {20, 85};
    std::vector<int> sizeBtn4 = {20, 85};
    while (done == false) {
        counter = _sfml.getEvent();
        if (counter == input::KEYDOWN && roomId < 4) {
            roomId++;
        } else if (counter == input::KEYUP && roomId > 1) {
            roomId--;
        } else if (counter == input::CLOSE) {
            return -1;
        } else if (counter == input::ENTER) {
            return roomId;
        }

        // _sfml.updateParallax();
        _sfml.drawText(posText, 100, "SpaceShipWarriorCombatED");
        _sfml.drawBox(posBtn1, sizeBtn1);
        _sfml.drawBox(posBtn2, sizeBtn2);
        _sfml.drawBox(posBtn3, sizeBtn3);
        _sfml.drawBox(posBtn4, sizeBtn4);
        _sfml.drawText(posText1, 40, "Room 1", roomId == 1 ? "yellow" : "green");
        _sfml.drawText(posText2, 40, "Room 2", roomId == 2 ? "yellow" : "green");
        _sfml.drawText(posText3, 40, "Room 3", roomId == 3 ? "yellow" : "green");
        _sfml.drawText(posText4, 40, "Room 4", roomId == 4 ? "yellow" : "green");

        _sfml.updateWindow();
    }
    return roomId;
}

int Client::readyMenu()
{
    input counter = input::NOTHING;
    bool done = false;

    std::cout << "launching menu" << std::endl;
    std::vector<int> posText = {10, 30};
    std::vector<int> posText1 = {55, 90};
    std::vector<int> posBtn1 = {50, 85};
    std::vector<int> sizeBtn1 = {20, 85};

    while (done == false) {
        counter = _sfml.getEvent();
        if (counter == input::CLOSE) {
            return -1;
        } else if (counter == input::ENTER) {
            return 1;
        }

        // _sfml.updateParallax();
        _sfml.drawText(posText, 100, "SpaceShipWarriorCombatED - Room");
        _sfml.drawBox(posBtn1, sizeBtn1);
        _sfml.drawText(posText1, 40, "You are ready?", "yellow");
        _sfml.updateWindow();
    }
    return 0;
}

void Client::stop()
{
    _running = false;
}

int Client::run() throw()
{
    input counter = input::NOTHING;

    _network.init();

    std::cout << "done with init" << std::endl;
    // wait until connected to server
    while (_network.isConnected() == false) {}

    _sfml.openWindow();
    int roomNb = selectRoomMenu();

    if (roomNb == -1) {
        stop();
        _network.stop();
        return 0;
    }

    _network.joinRoom(roomNb);

    std::cout << "connecting to the room" << std::endl;
    while (_network.isInRoom() == false) {}
    std::cout << "connected to the room" << std::endl;

    int ready = readyMenu();
    if (ready == -1 || ready == 0) {
        stop();
        _network.stop();
        return 0;
    }
    _network.readyToPlay();

    while (_running && counter != input::CLOSE) {
        counter = _sfml.getEvent();

        _network.sendInput(counter);

         // SEND LA SHIT AU SERVER

        _sfml.updateParallax();
         // RECUP LES REPONSES DU SERVER
        // _sfml.updateAllObject(getRendering());

        _sfml.drawBoundingBox(getBoundingBox());
        _sfml.drawAllObjects();
        _sfml.updateWindow();
    }
    stop();
    _network.stop();
    return 0;
}

std::vector<boundingBox> Client::getBoundingBox()
{
    std::vector<Packet> packet = _network.transfertQueueBoundingBoxes();
    std::vector<boundingBox> boundingbox;

    for (auto &&p : packet) {
        boundingBox box;
        if (p.getData(PRTL::CONTENT) == PRTL::CIRCLE) {
            box.type = shapeType::CIRCLE;
            std::pair<int, int> pos;
            pos.first = std::stoi(p.getData(PRTL::CIRCLE_POS_CENTER_Y));
            pos.second = std::stoi(p.getData(PRTL::CIRCLE_POS_CENTER_X));
            box.pos.push_back(pos);
            pos.first = std::stoi(p.getData(PRTL::CIRCLE_POS_RADIUS));
            pos.second = 0;
            box.pos.push_back(pos);
        } else if (p.getData(PRTL::CONTENT) == PRTL::SQUARE) {
            box.type = shapeType::SQUARE;
            std::pair<int, int> pos;
            pos.first = std::stoi(p.getData(PRTL::SQUARE_UPPERLEFT_Y));
            pos.second = std::stoi(p.getData(PRTL::SQUARE_UPPERLEFT_X));
            box.pos.push_back(pos);
            pos.first = std::stoi(p.getData(PRTL::SQUARE_UPPERRIGHT_Y));
            pos.second = std::stoi(p.getData(PRTL::SQUARE_UPPERRIGHT_X));
            box.pos.push_back(pos);
            pos.first = std::stoi(p.getData(PRTL::SQUARE_LOWERLEFT_Y));
            pos.second = std::stoi(p.getData(PRTL::SQUARE_LOWERLEFT_X));
            box.pos.push_back(pos);
            pos.first = std::stoi(p.getData(PRTL::SQUARE_LOWERRIGHT_Y));
            pos.second = std::stoi(p.getData(PRTL::SQUARE_LOWERRIGHT_X));
            box.pos.push_back(pos);
        }
        boundingbox.push_back(box);
    }
    return boundingbox;
}

std::vector<rendering> Client::getRendering()
{
    std::vector<rendering> rendering;

    //TODO: NICO: desobscrurcir le cote obscure de la force
    return rendering;
}