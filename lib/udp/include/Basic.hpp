#if !defined(BASIC_UDP_HPP)
#define BASIC_UDP_HPP

#include <boost/asio.hpp>
#include <unordered_map>
#include <string>

using boost::asio::ip::udp;

using dataPacket = std::unordered_map<std::string, std::string>;

struct UDPInfo {
	boost::asio::io_context& io_context;
	short port;
};

#endif // BASIC_UDP_HPP
