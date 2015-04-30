#include "socket.h"
#include "unixsocketimpl.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

//============================================
// Constructor
//=============================================
UnixSocketImpl::UnixSocketImpl(Port port) : port(port)
{
	tcp = getprotobyname("tcp");

	socket_addr.sin_family = AF_INET;
	socket_addr.sin_port = htons(port.port);
	inet_aton("10.204.130.239", (in_addr*)&socket_addr.sin_addr.s_addr);

	socket_fd = socket(PF_INET, SOCK_STREAM, tcp->p_proto);

	if (socket_fd == -1)
		throw new SocketException();

	if (bind(socket_fd, (sockaddr*)&socket_addr, sizeof socket_addr) == -1)
		throw new SocketException();

	if (listen(socket_fd, 1) == -1)
		throw new SocketException();

	fcntl(socket_fd, F_SETFL, O_NONBLOCK);
}

//============================================
// Destructor
//=============================================
UnixSocketImpl::~UnixSocketImpl()
{
	// close the socket
}

//============================================
// accept
//=============================================
unique_ptr<Connection> UnixSocketImpl::accept()
{
	int result = 12; //::accept(socket_fd, nullptr, nullptr);

	if (result == -1 && errno == EAGAIN)
		return nullptr;

	return unique_ptr<Connection>(new UnixConnectionImpl(result));
}