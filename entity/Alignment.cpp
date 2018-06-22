//
// Created by dylan on 6/19/2018.
//

#include "../headers/Alignment.h"
#include "../headers/FileManager.h"

#include <vector>
#include <algorithm>
#include <map>

using namespace dtrack::entity;

Alignment::Alignment() {
    unaligned = true;
    alignString = UNALIGNED_STRING;
}

Alignment::Alignment(Order ord, Morality mor) {
    order = ord;
    morality = mor;
    alignString = orderStrings[(int)ord] + " " + moralityStrings[(int)mor];
}

Alignment::Alignment(std::string alignment) {
    alignString = alignment;
    if(alignment == UNALIGNED_STRING) {
        unaligned = true;
    } else {
        vector<string> alTokens = dtrack::util::FileManager::tokenizeString(alignment, ' ');
        int pos = (find());
        order = stringToOrder[alTokens.at(0)];
        morality = stringToMorality[alTokens.at(1)];
    }
}

Order Alignment::getOrder() {
    return order;
}

Morality Alignment::getMorality() {
    return morality;
}

string Alignment::toString() {
    return alignString;
}
