Lab04: main.o FlightManager.o StarTrekShip.o StarWarsShip.o
	g++ -g -std=c++11 -Wall main.o FlightManager.o StarTrekShip.o StarWarsShip.o -o Lab04

main.o: main.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp SpaceShip.h StarTrekShip.h StarWarsShip.h
	g++ -g -std=c++11 -Wall -c main.cpp

StarTrekShip.o: StarTrekShip.h StarTrekShip.cpp
	g++ -g -std=c++11 -Wall -c StarTrekShip.cpp

StarWarsShip.o: StarWarsShip.h StarWarsShip.cpp
	g++ -g -std=c++11 -Wall -c StarWarsShip.cpp

FlightManager.o: FlightManager.h FlightManager.cpp
	g++ -g -std=c++11 -Wall -c FlightManager.cpp

clean:
	rm *.o Lab04
