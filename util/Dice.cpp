//
// Created by dylan on 6/17/2018.
//

#include "../headers/Dice.h"

#include <cstdlib>
#include <time.h>

using namespace dtrack::util;

Die::Die(int sides) {
    Die::sides = sides;
    int sum = 0;
    for(int count = 1; count <= Die::sides; count++) {
        sum += count;
    }
    Die::avg = ((double)sum) / Die::sides;
}

int Die::roll() {
    srand(rand() ^ time(NULL));
    return rand() % sides + 1;
}

int Die::roll(int times) {
    int sum = 0;
    for(int count = 0; count < times; count++) {
        sum += Die::roll();
    }
    return sum;
}

double Die::getAverage() {
    return Die::avg;
}
