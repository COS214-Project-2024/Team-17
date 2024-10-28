#ifndef CITIZENNAMEGEN_H
#define CITIZENNAMEGEN_H

#include <string>
#include <vector>

#define FIRST_NAMES_FILE "first-names.txt"
#define LAST_NAMES_FILE "last-names.txt"

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

private:
    /**
     * @brief Initializes the name lists by reading from files.
     *
     * This function reads first names and last names from predefined files and
     * stores them in static vectors. It also seeds the random number generator.
     */
    static void initialize();
};

#endif // CITIZENNAMEGEN_H