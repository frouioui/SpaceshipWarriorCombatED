#include <iostream>
#include "Server.hpp"
#include "GameEngine.hpp"

int main(int ac, char **argv)
{
    if (ac != 2) {
        std::cout << "usage: ./r-type_server 2000" << std::endl;
        return 84;
    }

    std::string port(argv[1]);
    std::srand(std::time(nullptr)); 
    try {
        boost::asio::io_context io_context;
        UDPInfo info = {io_context, static_cast<short>(std::stoi(port))};
        Server s(info);
        s.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "SERVER - ERROR" << std::endl;
    }
    return (0);
}