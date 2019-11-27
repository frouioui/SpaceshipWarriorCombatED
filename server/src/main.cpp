#include <iostream>
#include "Server.hpp"
#include "GameEngine.hpp"

GameEngine gameEngine;

int main(int ac, char **argv)
{
    (void)ac;
    (void)argv;
    try {
        boost::asio::io_context io_context;
        UDPInfo info = {io_context, 2000};
        Server s(info);
        s.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}