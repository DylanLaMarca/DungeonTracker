//
// Created by dylan on 6/17/2018.
//

#include "../../headers/Attack.h"
#include "../../headers/Dice.h"
#include "../../headers/ANSI.h"

#include <string>
#include <map>

using namespace dtrack::entity;

void printDamage(Damage dmg, int amt) {
    dtrack::util::ANSI::printColor(std::to_string(amt) + " ", dtrack::util::ANSI::Color::WHITE, false);
    dtrack::util::ANSI::printColor(damageNames[dmg], dtrack::util::ANSI::Color::WHITE, false);
}

Attack::Attack(dtrack::entity::Damage dmg, int dieSides, int num, int bonus) : die(dieSides) {
    modBonus = bonus;
    type = dmg;
    dieNum = num;
}

Damage Attack::damageType() {
    return type;
}

int Attack::rollDamage() {
    return die.roll() + modBonus;
}
