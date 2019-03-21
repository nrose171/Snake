all: main

main: main.cpp Snake.o Dot.o Grid.o
	g++ main.cpp Snake.o Dot.o Grid.o -o main -lncurses

Snake.o: Snake.cpp
	g++ -c Snake.cpp

#Dot.o: Dot.cpp
#	g++ -c Dot.cpp

#Grid.o: Grid.cpp
#	g++ -c Grid.cpp

clean:
	rm -rf *o main
