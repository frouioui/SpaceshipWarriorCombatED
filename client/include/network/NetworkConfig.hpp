#if !defined(NETWORK_CONFIG_HPP)
#define NETWORK_CONFIG_HPP

#include <string>

class NetworkConfig
{
public:
    NetworkConfig();
    NetworkConfig(const std::string &server_ip, short server_port);

    ~NetworkConfig();

    void setServerIp(const std::string &ip);
    void setGameServerIp(const std::string &ip);
    void setServerPort(unsigned short port);
    void setGameServerPort(unsigned short port);

    const std::string &getServerIp() const;
    const std::string &getGameServerIp() const;
    short getServerPort() const;
    short getGameServerPort() const;

private:
    std::string _server_ip;
    std::string _game_server_ip;
    short _server_port;
    short _game_server_port;
};




#endif // NETWORK_CONFIG_HPP
