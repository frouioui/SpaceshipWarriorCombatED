#ifndef UDP_HPP_
#define UDP_HPP_

#include <map>
#include <unordered_map>
#include <boost/asio.hpp>

#include "Basic.hpp"
#include "Packet.hpp"

class UDP
{
public:
	UDP(UDPInfo &info) : _socket(info.io_context, udp::endpoint(udp::v4(), info.port)) {_port = info.port;}
	~UDP();

	void receive();
	void send(Packet packet);

protected:

private:
	short _port;
	udp::socket _socket;
	udp::endpoint _endpoint;

	dataPacket stringToMap(std::string string) const;
	std::string mapToString(const dataPacket &map) const;

};

#endif /* !UDP_HPP_ */
