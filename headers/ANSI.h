//
// Created by dylan on 6/16/2018.
//

#ifndef DUNGEONTRACKER_COLOR_H
#define DUNGEONTRACKER_COLOR_H

#include <stdint-gcc.h>
#include <string>

namespace dtrack::util {
    class ANSI {
    private:
        static std::string PREFIX;
        static std::string SUFFIX_UND;
        static std::string SUFFIX;
        static std::string RESET;

        static void printNewLine(bool newline);
    public:
        enum class Color {
            BLACK = 30, RED = 31, GREEN = 32, YELLOW = 33,
            BLUE = 34, MAGENTA = 35, CYAN = 36, WHITE = 37,
            BR_BLACK = 90, BR_RED = 91, BR_GREEN = 92, BR_YELLOW = 93,
            BR_BLUE = 94, BR_MAGENTA = 95, BR_CYAN = 96, BR_WHITE = 97
        };

        static void printColor(std::string text, Color color, bool newline);
        static void printUnderlinedColor(std::string text, Color color, bool newline);
    };
}





#endif //DUNGEONTRACKER_COLOR_H
