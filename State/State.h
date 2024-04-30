#ifndef __State_H__
#define __State_H__
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class State {

  public:

    State(istream &is);

    void read_from(istream &is);

    ~State();

    void write_to(ostream &os);

    void update(string input);


};

#endif