#pragma once

#include "socket.h"
#include "unixsocketimpl.h"
#include "memory.h"

struct SocketFactory
{
	static unique_ptr<Socket> from_port(Port port)
	{
		return make_unique<UnixSocketImpl>(port);
	}
};