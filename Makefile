main: main.o board.o
	g++ -o main main.o board.o

main.o: main.cpp
	g++ -c main.cpp -std=c++11

board.o: board.cpp
	g++ -c board.cpp -std=c++11
