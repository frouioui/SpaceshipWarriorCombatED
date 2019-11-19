#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_


namespace Connection
{

	enum Mode {
		NOTDEFINED,
		TCP,
		UDP
	};

	class Connections
	{
	public:
		virtual ~Connections() {};

		virtual void accept() = 0;
		virtual void send() = 0;
		virtual const std::string &receive() = 0;
		virtual void connect() = 0;


	private:
		virtual void listen(int port) = 0;
		virtual void bind() = 0;

	};

} // namespace Connection


#endif /* !CONNECTION_HPP_ */