#if !defined(PLAYER_HPP)
#define PLAYER_HPP

#include <string>

class Player
{
public:
    Player();
    ~Player();

    void setUsername(const std::string &username);
    const std::string &getUsername() const;

private:
    std::string _username;
};

#endif // PLAYER_HPP
