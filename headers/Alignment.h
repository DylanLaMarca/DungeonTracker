//
// Created by dylan on 6/19/2018.
//

#ifndef DUNGEONTRACKER_ALIGNMENT_H
#define DUNGEONTRACKER_ALIGNMENT_H

#include <string>
#include <map>
#include <vector>

using namespace std;

namespace dtrack::entity {
    enum class Order { LAWFUL, NUETRAL, CHAOTIC };
    static vector<string> orderStrings = {"lawful","nuetral,"chaotic};

    enum class Morality { GOOD, NUETRAL, EVIL };
    static vector<string> moralityStrings = {"good","nuetral","evil"};

    static string UNALIGNED_STRING = "unaligned";
    class Alignment {
    private:
        string alignString;
        bool unaligned;
        Order order;
        Morality morality;

    public:
        Alignment();
        Alignment(Order ord, Morality mor);
        Alignment(std::string alignment);

        Order getOrder();
        Morality getMorality();
        string toString();
    };
}

#endif //DUNGEONTRACKER_ALIGNMENT_H
