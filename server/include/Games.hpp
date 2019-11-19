#ifndef GAMES_HPP
#define GAMES_HPP

#include <string>
#include "Connection.hpp"

class Games
{
public:
	Games();
	~Games();

	void run(int port, const std::string &name) throw();

protected:
private:
    std::string _name;
    int _port;
  
    std::unique_ptr<Connection::Connections> _connection;

};

#endif /* !GAMES_HPP */
