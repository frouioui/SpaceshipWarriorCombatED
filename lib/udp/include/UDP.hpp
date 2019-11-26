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
	UDP(UDPInfo &info);
	UDP(UDP &source);
	~UDP();

	Packet receive();
	void send(Packet packet);
	void finish();

protected:

private:
	short _port;
	boost::asio::io_context& _context;

	udp::socket _socket;
	udp::endpoint _endpoint;

	dataPacket stringToMap(std::string string) const;
	std::string mapToString(const dataPacket &map) const;

};

#endif /* !UDP_HPP_ */
