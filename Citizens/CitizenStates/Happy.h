#ifndef HAPPY_H
#define HAPPY_H

#include "../CitizenState.h"

class Happy : public CitizenState {
public:
    void handleChange();
    std::string getState();
    ~Happy() {};
};

#endif
