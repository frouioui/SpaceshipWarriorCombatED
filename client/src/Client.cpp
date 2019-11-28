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

int Client::run() throw()
{
    input counter = input::NOTHING;

    _network.init();

    std::cout << "done with init" << std::endl;

    // wait until connected to server
    while (_network.isConnected() == false) {}

    // TEST
    // std::cout << "connected" << std::endl;
    _network.createAndJoinRoom();
    // std::cout << "now about to run" << std::endl;
    // _network.getAvailableRooms();

    _sfml.openWindow();

    while (_running && counter != input::CLOSE) {
        counter = _sfml.getEvent();

        _network.sendInput(counter);

         // SEND LA SHIT AU SERVER

        _sfml.updateParallax();

         // RECUP LES REPONSES DU SERVER

        _sfml.drawBoundingBox(getBoundingBox());
        _sfml.updateWindow();
    }
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