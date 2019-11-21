#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "UDP.hpp"

class Server
{
public:
	Server(boost::asio::io_context& io_context, short port);
	~Server();

	int run() throw();

protected:

private:
	UDP _udp_server;

	bool _running;
};

#endif /* !SERVER_HPP_ */
