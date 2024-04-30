Main:  Helpers.o State.o Main.o
	g++ -Wall Main.o Helpers.o State.o -o Main
Main.o:  Main.cpp
	g++ -Wall -c Main.cpp
Helpers/Helpers.o:  Helpers.cpp Helpers.h
	g++ -Wall -c Helpers.cpp
State/State.o: State.cpp State.h
	g++ -Wall -c State.cpp


