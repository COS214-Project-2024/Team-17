#ifndef COLOURS_H
#define COLOURS_H

#include <string>
#include <iostream>
using namespace std;

// TESTING COLOURS
/**
 * @brief ANSI escape codes for terminal text colors.
 *
 * These constants can be used to change the color of text output in the terminal.
 */
const string RESET = "\033[0m";
const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string PURPLE = "\033[35m";
const string CYAN = "\033[36m";

const string BG_BLACK = "\033[40m";
const string BG_WHITE = "\033[47m";
// TESTING COLOURS
/**
 * @enum Colour
 * @brief Enum class representing color options.
 *
 * Currently empty, but can be expanded for specific color definitions or usage within the application.
 */
enum class Colour
{
    // keep empty
};

#endif // COLOURS_H


