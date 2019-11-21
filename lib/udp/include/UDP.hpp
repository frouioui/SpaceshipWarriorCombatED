#ifndef UDP_HPP_
#define UDP_HPP_

#include <map>
#include <unordered_map>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::udp;

class UDP
{
public:
	UDP(boost::asio::io_context& io_context, short port) : _socket(io_context, udp::endpoint(udp::v4(), port)) {_port = port;}
	~UDP();

	void receive();
	void send();

	const std::unordered_map<std::string, std::string> &stringToMap(std::string string) const;

protected:

private:
	short _port;
	udp::socket _socket;
	udp::endpoint _receive_endpoint;
};

#endif /* !UDP_HPP_ */
