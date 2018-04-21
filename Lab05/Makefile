Lab05: main.o PreconditionViolationException.o Theater.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o Theater.o -o Lab05

main.o: main.cpp Node.h Node.hpp PreconditionViolationException.h Queue.h Queue.hpp QueueInterface.h Stack.h Stack.hpp StackInterface.h Theater.h
	g++ -g -std=c++11 -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp

Theater.o: Theater.h Theater.cpp
	g++ -g -std=c++11 -Wall -c Theater.cpp

clean:
	rm *.o Lab05
