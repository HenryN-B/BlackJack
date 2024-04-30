#ifndef __State_H__
#define __State_H__
#include <fstream>

class State {
    int playerCount;
    std::string* playerCards;
    int dealerCount;
    std::string* dealerCards;
    std::string* deck;
    int playerHitCount;
    int dealerHitCount;
    int bet;
    int money;
  public:
    bool reSuffle , acePlayer, aceDealer, reveal;
    int page;

    State(std::istream &is);

    void read_from(std::istream &is);

    ~State();

    void write_to(std::ostream &os);

    void update(std::string input);

    std::string* getDealerCards();

    std::string* getPlayerCards();

};

#endif