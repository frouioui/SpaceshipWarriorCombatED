#include <exception>
#include <iostream>
#include "Server.hpp"

Server::Server(boost::asio::io_context& io_context, short port) : _udp_server(io_context, port)
{
	_running = true;
}

Server::~Server()
{
}

int Server::run() throw()
{
	while (_running) {
		try {
			std::cout << "get input" << std::endl;
			_udp_server.receive();
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
