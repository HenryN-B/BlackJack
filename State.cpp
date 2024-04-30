#include "State.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


State::State(std::istream &is) { 
    read_from(is); 
}

void State::read_from(std::istream &is) {
    std::string tmp;
    getline(is, tmp);
    is >> reSuffle;
    is >> acePlayer;
    is >> aceDealer;
    is >> reveal;
    is >> playerCount;
    is >> dealerCount;
    is >> playerHitCount;
    is >> dealerHitCount;
    is >> bet;
    is >> money;
    is >> page;
    getline(is, tmp);
    getline(is, tmp);
    playerCards = new std::string[12];
    for(int i=0; i<12; i++) {
        getline(is, tmp);
        playerCards[i] = tmp;
    }
    getline(is, tmp);
    dealerCards = new std::string[12];
    for(int i=0; i<12; i++) {
        getline(is, tmp);
        dealerCards[i] = tmp;
    }
    getline(is, tmp);
    deck = new std::string[52];
    for(int i=0; i<52; i++) {
        getline(is, tmp);
        deck[i] = tmp;
    }
    
}

State::~State() {
    delete [] playerCards;
    delete [] dealerCards;
    delete [] deck;
}

void State::write_to(std::ostream &os) {
    os << "#Vars" << std::endl;
    os << reSuffle << " ";
    os << acePlayer << " ";
    os << aceDealer << " ";
    os << reveal << " ";
    os << playerCount << " ";
    os << dealerCount << " ";
    os << playerHitCount << " ";
    os << dealerHitCount << " ";
    os << bet << " ";
    os <<  money << " ";
    os << page << " " << std::endl;
    os << "#PlayerCards" << std::endl;
    for(int i=0; i<12; i++) {
        os << playerCards[i] << std::endl;
    }
    os << "#DealerCards" << std::endl;
    for(int i=0; i<12; i++) {
        os << dealerCards[i] << std::endl;
    }
    os << "#Deck" << std::endl;
    for(int i=0; i<52; i++) {
        os << deck[i] << std::endl;
    }
    


}

void State::update(std::string input) {

}

std::string* State::getDealerCards() {
    return dealerCards;
}

std::string* State::getPlayerCards() {
    return playerCards;
}