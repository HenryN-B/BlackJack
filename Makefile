Main:  Blackjack/Blackjack.o Helpers/Helpers.o State/State.o Main.o
	g++ -Wall Main.o Blackjack/Blackjack.o Helpers/Helpers.o State/State.o -o Main
Blackjack.o:  Blackjack/Blackjack.cpp Blackjack/Blackjack.h
	g++ -Wall -cBlackjack/ Blackjack.cpp
Main.o:  Main.cpp
	g++ -Wall -c Main.cpp
Helpers/Helpers.o:  Helpers/Helpers.cpp Helpers/Helpers.h
	g++ -Wall -c Helpers/Helpers.cpp
State/State.o: State/State.cpp State/State.h
	g++ -Wall -c State/State.cpp


