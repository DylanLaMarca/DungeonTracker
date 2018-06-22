//
// Created by dylan on 6/19/2018.
//

#ifndef DUNGEONTRACKER_FILEMANAGER_H
#define DUNGEONTRACKER_FILEMANAGER_H

#include <string>
#include <vector>

using namespace std;

namespace dtrack::util {
    class FileManager {
    public:
        static void genMonster(std::string monFile);
        static vector<string> tokenizeString(string line, char c);
    private:
        static void parseList(string list, void (*fcn)(string));
    };
}


#endif //DUNGEONTRACKER_FILEMANAGER_H
