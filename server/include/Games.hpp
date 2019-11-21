#ifndef GAMES_HPP
#define GAMES_HPP

#include <string>

class Games
{
public:
	Games();
	~Games();

	void run(int port, const std::string &name) throw();

protected:
private:

};

#endif /* !GAMES_HPP */
