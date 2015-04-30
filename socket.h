#pragma once

#include <exception>
#include <string>

struct Port
{
	Port(int port) { this->port = port; }
	int port;
};

class Socket
{
public:
	virtual ~Socket() { }

	virtual bool has_connection() = 0;
	virtual unique_ptr<Connection> accept() = 0;

};

class SocketException : public std::exception
{
};

class Connection
{
public:
	virtual ~Connection() { }

	virtual void write(std::string) = 0;
	virtual std::string read() = 0;
};