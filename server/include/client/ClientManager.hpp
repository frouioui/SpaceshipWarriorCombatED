#if !defined(CLIENT_MANAGER_HPP)
#define CLIENT_MANAGER_HPP

#include <vector>
#include "client/Client.hpp"

class ClientManager
{
public:
    ClientManager();
    ~ClientManager();

    void addClient(Client client);

    std::string generateToken() const;
    bool userExists(const std::string &token) const;

private:
    std::vector<Client> _clients;
    std::string generateOneToken() const;
};

#endif // CLIENT_MANAGER_HPP