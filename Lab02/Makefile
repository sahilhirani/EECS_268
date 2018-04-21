Lab02: main.o Executive.o LinkedListTester.o
	g++ -g -std=c++11 -Wall main.o Executive.o LinkedListTester.o -o Lab02

main.o: main.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

LinkedListTester.o: LinkedListTester.h LinkedListTester.cpp
	g++ -g -std=c++11 -Wall -c LinkedListTester.cpp

clean:
	rm *.o Lab02
