#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "network/NetworkManager.hpp"

class Client {
public:
	Client(UDPInfo &info);
	~Client();

	int run() throw();

protected:

private:
	NetworkManager _network;

	bool _running;
};

#endif /* !CLIENT_HPP_ */
