#include "unixsocketimpl.h"

//============================================
// Constructor
//=============================================
UnixConnectionImpl::UnixConnectionImpl(int socket_fd) : socket_fd(socket_fd)
{

}

//============================================
// Destructor
//=============================================
UnixConnectionImpl::~UnixConnectionImpl()
{

}

//=============================================
// write
//=============================================
void UnixConnectionImpl::write(std::string)
{

}

//============================================
// read
//=============================================
std::string UnixConnectionImpl::read()
{

}