#include "Client.hpp"

int main(int ac, char **argv)
{
    (void)ac;
    (void)argv;

    boost::asio::io_context io_context;
    UDPInfo info = {io_context, 100};

    Client client(info);

    client.run();

    return 0;
}
