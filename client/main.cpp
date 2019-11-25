#include <iostream>
#include "Client.hpp"
#include "Sfml.hpp"

int main(int ac, char **argv)
{
    // (void)ac;
    // (void)argv;
    // Client client;
    // Sfml sfml;

    // sfml.loadBackground();
    // sfml.loadAsset();
    // sfml.openWindow();
    // sfml.updateWindow();
    // client.run();

    (void)argc;
    (void)argv;

    boost::asio::io_context io_context;
    UDPInfo info = {io_context, 100};

    Client client(info, "127.0.0.1", 99);

    client.run();

    return 0;
}