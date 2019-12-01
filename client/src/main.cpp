#include "Client.hpp"

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cout << "usage: ./r-type_client 127.0.0.1 2000 2001" << std::endl << "args: ip port_server port_client" << std::endl;
        return 84;
    }

    std::string ip_server(argv[1]);
    std::string port(argv[2]);
    std::string port_client(argv[3]);

    boost::asio::io_context io_context;
    UDPInfo info = {io_context, static_cast<short>(std::stoi(port_client))};
    Client client(info, ip_server, static_cast<short>(std::stoi(port)));

    try {
        client.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "CLIENT - ERROR" << std::endl;
    }
    client.stop();
    return 0;
}
