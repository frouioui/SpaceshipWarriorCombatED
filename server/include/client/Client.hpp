#if !defined(CLIENT_HPP)
#define CLIENT_HPP

#include <string>

class Client
{
public:
    Client();
    ~Client();

    void setIp(const std::string &ip);
    void setPort(short port);
    void setToken(const std::string &token);
    void setUsername(const std::string &username);
    void setPlayerId(unsigned short player_id);

    const std::string &getIp() const;
    short getPort() const;
    const std::string &getToken() const;
    const std::string &getUsername() const;
    unsigned short getPlayerId() const;

private:
    std::string _ip;
    short _port;
    std::string _token;
    std::string _username;
    unsigned short _player_id;
};

#endif // CLIENT_HPP
