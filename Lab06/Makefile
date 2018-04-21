Executive: main.o Executive.o MazeReader.o MazeWalker.o PreconditionViolationException.o
	g++ -std=c++11 -g -Wall main.o MazeReader.o MazeWalker.o PreconditionViolationException.o Executive.o -o Executive

main.o: main.cpp Executive.h MazeReader.h MazeWalker.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp MazeReader.h MazeWalker.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -std=c++11 -g -Wall -c MazeWalker.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -std=c++11 -g -Wall -c MazeReader.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp

clean:
	rm *.o Executive
