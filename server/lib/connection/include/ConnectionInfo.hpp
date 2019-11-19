#ifndef CONNECTIONINFO_HPP_
#define CONNECTIONINFO_HPP_

#include <string>

class ConnectionInfo
{
public:
	ConnectionInfo();
	~ConnectionInfo();

    void setName(const std::string &name);
    void setID(const int id);
    int getID() const;
    const std::string &getName() const;

protected:

private:
    int _id;
    std::string _name;
};

#endif /* !CONNECTIONINFO_HPP_ */