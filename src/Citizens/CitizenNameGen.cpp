#include "CitizenNameGen.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>

static std::vector<std::string> firstNames;
static std::vector<std::string> lastNames;

std::string CitizenNameGen::generateName()
{
    static bool init = false;
    if (!init)
    {
        initialize();
        init = true;
    }
    // Picks two random numbers between 0 and 100
    int firstIndex = rand() % 100;
    int lastIndex = rand() % 100;

    // Return the line at the index of the random number of the respective text file
    return firstNames[firstIndex] + " " + lastNames[lastIndex];
}

void CitizenNameGen::initialize()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    srand(static_cast<unsigned int>(millis));

    // Read first names from file
    std::ifstream firstNamesFile(FIRST_NAMES_FILE);
    std::string line;
    while (std::getline(firstNamesFile, line))
    {
        firstNames.push_back(line);
    }
    firstNamesFile.close();

    // Read last names from file
    std::ifstream lastNamesFile(LAST_NAMES_FILE);
    while (std::getline(lastNamesFile, line))
    {
        lastNames.push_back(line);
    }
    lastNamesFile.close();
}