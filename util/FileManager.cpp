#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "../headers/FileManager.h"

using namespace std;
using namespace dtrack::util;

void FileManager::genMonster(string monFile) {
    string line;
    ifstream file (monFile);
    int count = 0;
    if (file.is_open()) {
        while(getline(file,line)) {
            istringstream monStream(line);
            string token;
            string value;
            while (getline(monStream, token, ':')) {
                getline(monStream, value);

                if(token.at(0) == '[') {
//                    vector<string> elements = FileManager::parseList(token);
                } else {
                    cout << count << ": " << token << "\n";
                }
            }
            count += 1;
        }
        file.close();
    } else {
        cout << "Unable to open file";
    }
}

vector<string> FileManager::tokenizeString(string line, char c) {
    vector<string> tokens;
    istringstream listStream(line);
    string token;
    while (getline(listStream, token, c)) {
        tokens.push_back(token);
    }
    return tokens;
}

void FileManager::parseList(string list, void (*fcn)(string)) {
    list.erase(0, 1);
    list.erase(list.length()-1, list.length());
    vector<string> elements = tokenizeString(list, ',');
}
