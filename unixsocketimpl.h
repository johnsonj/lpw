#pragma once

#include "socket.h"
#include "memory.h"
#include <netinet/ip.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>


class UnixSocketImpl : public Socket
{
public:
	UnixSocketImpl(Port port);
	~UnixSocketImpl();

	bool has_connection();

	unique_ptr<Connection> accept();
private:
	Port port;
	struct protoent* tcp;
	struct sockaddr_in socket_addr;
	int socket_fd;
};

class UnixConnectionImpl : public Connection
{
	~UnixConnectionImpl();
private:
	UnixConnectionImpl(int socket_fd);

	void write(std::string val);
	std::string read();

private:
	int socket_fd;

	friend class UnixSocketImpl;
};