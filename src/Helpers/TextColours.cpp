#include <iostream>
#include <string>

class TextColours
{
public:
    static const std::string TEXT_RESET;
    static const std::string TEXT_BLACK;
    static const std::string TEXT_RED;
    static const std::string TEXT_GREEN;
    static const std::string TEXT_YELLOW;
    static const std::string TEXT_BLUE;
    static const std::string TEXT_PURPLE;
    static const std::string TEXT_CYAN;
    static const std::string TEXT_WHITE;
};

const std::string TextColours::TEXT_RESET = "\033[0m";
const std::string TextColours::TEXT_BLACK = "\033[30m";
const std::string TextColours::TEXT_RED = "\033[31m";
const std::string TextColours::TEXT_GREEN = "\033[32m";
const std::string TextColours::TEXT_YELLOW = "\033[33m";
const std::string TextColours::TEXT_BLUE = "\033[34m";
const std::string TextColours::TEXT_PURPLE = "\033[35m";
const std::string TextColours::TEXT_CYAN = "\033[36m";
const std::string TextColours::TEXT_WHITE = "\033[37m";
