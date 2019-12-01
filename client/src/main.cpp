#include "Client.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    boost::asio::io_context io_context;
    UDPInfo info = {io_context, 2003};
    Client client(info, "127.0.0.1", 2000);

    try {
        client.run();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    client.stop();
    return 0;
}
