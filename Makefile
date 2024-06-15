output: main.o loadbalancer.o server.o request.o
	g++ main.o loadbalancer.o server.o request.o -o output

main.o: main.cpp
	g++ -c main.cpp

loadbalancer.o: loadbalancer.cpp loadbalancer.h
	g++ -c loadbalancer.cpp

server.o: server.cpp server.h
	g++ -c server.cpp

request.o: request.cpp request.h
	g++ -c request.cpp

clean:
	rm *.o output