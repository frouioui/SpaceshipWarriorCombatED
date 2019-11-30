#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "network/NetworkManager.hpp"
#include "Sfml.hpp"

class Client {
public:
	Client(UDPInfo &info);
	Client(UDPInfo &info, const std::string &server_ip, short server_port);

	~Client();

	int run() throw();
	void stop();

protected:

private:
	NetworkManager _network;

	Sfml _sfml;

	bool _running;

	std::vector<boundingBox> getBoundingBox();
    std::vector<rendering> getRendering();
};

#endif /* !CLIENT_HPP_ */
