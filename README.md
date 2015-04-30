# light, portable web server #

## Goals ##
1. Single executable with no unusual dependencies
2. Cross platform (It'd be Windows first if I had VC installed on this laptop)
3. Static assets
4. Replace apache (jokes)

## Execution ##

Run lpw directly from where you want to serve the content

## Threading ##

Oh why not let's thread this thing like crazy. Single process. Requests will get pushed into a queue and worker threads will pop them and process them. Single lock on that. The main thread will be responsible for the actual sockets but that could change.

## Project Structure ##

main.cpp: Entry point, main thread?
worker.cpp: Process requests here!
connection.cpp: There will probably be a big god class here.
threadpool.cpp: It could happen, reserve the name for now
requestpresenter.cpp: This is a class we can hand junk from a HTTP request and get back a usuable object


## Platform Abstractions ##

Socket - interface
UnixSocketImpl