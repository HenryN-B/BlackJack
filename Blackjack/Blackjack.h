#ifndef __Blackjack_H__
#define __Blackjack_H__


#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <string>
using namespace std;


class Blackjack {
private:
    bool reSuffle;
    bool aceP;
    bool aceD;
    bool reveal;
    int playerCount;
    int playerCards[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int dealerCount;
    int dealerCards[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int* deck;
    int playerHitCount;
    int dealerHitCount;
    int bet;
    int money;

public:
    //function to get random card
    int randCard();
    
    //shuffles the deck and puts all cards back into the deck 
    int* shuffleDeck();
    
    void deal();

    void winCheck();

    void hit(string str);

    void printGameBoard();

    void stay();

    void askForBet();

    void countReSet();

    Blackjack();

    void play();
};

#endif