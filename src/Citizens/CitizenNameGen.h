#ifndef CITIZENNAMEGEN_H
#define CITIZENNAMEGEN_H

#include <string>

/**
 * @class CitizenNameGen
 * @brief A class to generate random citizen names.
 *
 * This class reads first names and last names from files and generates
 * random full names by combining a random first name with a random last name.
 */
class CitizenNameGen
{
public:
    /**
     * @brief Generates a random full name.
     *
     * This function generates a random full name by combining a random first name
     * with a random last name. The names are read from predefined files.
     *
     * @return A randomly generated full name.
     */
    static std::string generateName();
};

#endif // CITIZENNAMEGEN_H