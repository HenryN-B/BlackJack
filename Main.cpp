
#include <iostream>
#include <fstream>
#include <string>
#include "Blackjack/Blackjack.h"
#include "State/State.h"
#include "Helpers/Helpers.h"

int main() {
  bool just_starting = true;
  while(1) {
    ifstream fs1(just_starting ? "initial_state" : "curr_state");
    State state(fs1);
    fs1.close();

    string input;
    if (just_starting) just_starting = false;
    else getline(cin, input);

    state.update(input);
    display(state);

    ofstream fs2("curr_state");
    state.write_to(fs2);
  }
}


