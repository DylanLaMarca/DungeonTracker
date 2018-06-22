
#include "../headers/ANSI.h"

#include <iterator>
#include <iostream>

using namespace dtrack::util;

    std::string ANSI::PREFIX = "\033[";
    std::string ANSI::SUFFIX_UND = ";1;4m";
    std::string ANSI::SUFFIX = ";1m";
    std::string ANSI::RESET = "\033[0m";

    void ANSI::printColor(std::string text, ANSI::Color color, bool newline) {
        std::cout << PREFIX << (int)color << SUFFIX;
        std::cout << text << RESET;
        ANSI::printNewLine(newline);
    }

    void ANSI::printUnderlinedColor(std::string text, ANSI::Color color, bool newline) {
        std::cout << PREFIX << (int)color << SUFFIX_UND;
        std::cout << text << RESET;
        ANSI::printNewLine(newline);
    }

    void ANSI::printNewLine(bool newline) {
        if(newline) {
            std::cout << "\n";
        }
    }
