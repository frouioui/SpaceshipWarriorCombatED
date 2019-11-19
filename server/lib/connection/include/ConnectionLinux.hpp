#ifndef CONNECTIONLINUX_HPP_
#define CONNECTIONLINUX_HPP_

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "Connection.hpp"

namespace Connection
{

    class ConnectionLinux : public Connection::Connections
    {
    public:
        virtual ~ConnectionLinux();

        void accept(const Connection::Mode &mode = Connection::Mode::NOTDEFINED);
        void send(const std::string &data, const std::string &ip, int port);
        const std::string &receive();
        void connect();


    private:
        void listen(int port);
        void bind();

        int _socket;
        struct sockaddr_in _addr;
        std::string _mode;

    };


} // namespace Connection

#endif /* !CONNECTIONLINUX_HPP_ */