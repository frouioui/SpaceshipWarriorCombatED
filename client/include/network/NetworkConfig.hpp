#if !defined(NETWORK_CONFIG_HPP)
#define NETWORK_CONFIG_HPP

#include <string>

class NetworkConfig
{
public:
    NetworkConfig();
    NetworkConfig(const std::string &server_ip, short server_port);

    ~NetworkConfig();

    const std::string &getServerIp() const;
    short getServerPort() const;

private:
    std::string _server_ip;
    short _server_port;
};




#endif // NETWORK_CONFIG_HPP
