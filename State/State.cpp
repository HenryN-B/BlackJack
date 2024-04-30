#include "State.h"

State::State(istream &is) { 
    read_from(is); 
}

void State::read_from(istream &is) {

}

State::~State() {

}

void State::write_to(ostream &os) {

}

void State::update(string input) {

}

int* State::getDealerCards() {
    return b1.dealerCards;
}