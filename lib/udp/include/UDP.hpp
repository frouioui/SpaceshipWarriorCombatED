#ifndef UDP_HPP_
#define UDP_HPP_

#include <map>
#include <unordered_map>

#include <boost/asio.hpp>

using boost::asio::ip::udp;

struct UDPInfo {
	boost::asio::io_context& io_context;
	short port;
};

class UDP
{
public:
	UDP(UDPInfo &info) : _socket(info.io_context, udp::endpoint(udp::v4(), info.port)) {_port = info.port;}
	~UDP();

	void receive();
	void send(const std::string &data, const std::string &ip, short port);

protected:

private:
	short _port;
	udp::socket _socket;
	udp::endpoint _endpoint;

	std::unordered_map<std::string, std::string> stringToMap(std::string string) const;

};

#endif /* !UDP_HPP_ */
