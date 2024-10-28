#ifndef CONTENT_H
#define CONTENT_H

#include "../CitizenState.h"

class Content : public CitizenState {
public:
    void handleChange();
    std::string getState();
    ~Content() {};
};

#endif
