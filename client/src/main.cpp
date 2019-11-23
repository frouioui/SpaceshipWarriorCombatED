#include "Client.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    boost::asio::io_context io_context;
    UDPInfo info = {io_context, 100};

    Client client(info, "127.0.0.1", 99);

    client.run();

    return 0;
}
