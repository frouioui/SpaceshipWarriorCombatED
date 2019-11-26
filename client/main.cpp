#include <iostream>
#include "Client.hpp"
#include "Sfml.hpp"

int main(int ac, char **argv)
{
    (void)ac;
    (void)argv;
    Client client;
    Sfml sfml;

    // sfml.loadBackground();
    // sfml.loadAsset();
    sfml.openWindow();
    sfml.updateWindow();
    // client.run();
    return 0;
}