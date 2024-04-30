#ifndef __State_H__
#define __State_H__
#include <fstream>
#include "../Blackjack/Blackjack.h"

class State {
    Blackjack b1;

  public:

    State(std::istream &is);

    void read_from(std::istream &is);

    ~State();

    void write_to(std::ostream &os);

    void update(std::string input);

    int* getDealerCards();

};

#endif