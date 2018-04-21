Lab09: main.o Exception.o Warehouse.o Package.o
	g++ -g -std=c++11 -Wall main.o Exception.o Warehouse.o Package.o -o Lab09

main.o: main.cpp Exception.h Warehouse.h Heap.h Heap.hpp HeapInterface.h Package.h
	g++ -g -std=c++11 -Wall -c main.cpp

Warehouse.o: Warehouse.h Warehouse.cpp Package.o Exception.o
	g++ -g -std=c++11 -Wall -c Warehouse.cpp

Exception.o: Exception.h Exception.cpp
	g++ -g -std=c++11 -Wall -c Exception.cpp

Package.o: Package.h Package.cpp
	g++ -g -std=c++11 -Wall -c Package.cpp

clean:
	rm *.o Lab09
