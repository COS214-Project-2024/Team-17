#ifndef CITIZENNAMEGEN_H
#define CITIZENNAMEGEN_H

#include <string>
#include <vector>

#define FIRST_NAMES_FILE "first-names.txt"
#define LAST_NAMES_FILE "last-names.txt"

class CitizenNameGen
{
public:
    static std::string generateName();

private:
    static void initialize();
};

#endif // CITIZENNAMEGEN_H