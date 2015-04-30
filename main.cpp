/*
 * lpw - Light, portable webserver
 *
 */

 #include <iostream>
 #include <thread>
 #include <chrono>
 #include "memory.h"
 #include "socketfactory.h"

int main(int /*argc*/, char** /*argv*/)
{
	std::cout << "lpw - light, portable web server" << std::endl;

	// initialize socket(s)
	Port p(3333);
	unique_ptr<Socket> socket = SocketFactory::from_port(p);

	// initialize threads


	// begin main loop

	while (true)
	{
		if (socket->HasConnection())
		{
			std::cout << "Got one!" << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << ".";
	}

	return 0;
}