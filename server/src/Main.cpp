#include <iostream>
#include "Server.hpp"

int main(int ac, char **argv)
{
    (void)ac;
    (void)argv;
    try {
        boost::asio::io_context io_context;
        Server s(io_context, 99);
        s.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}