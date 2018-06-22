//
// Created by dylan on 6/17/2018.
//
#include <cmath>
#include <iostream>
#include <string>

#include "../headers/Creature.h"
#include "../headers/CreatureElements.h"
#include "../headers/ANSI.h"

using namespace dtrack::entity;

Creature::Creature() {
    cr20 = dtrack::util::d20();
}

Creature::Creature(std::string name, int level, int hp, int str, int dex, int con, int intel, int wis, int cha) {
    Creature::name = name;
    Creature::level = level;
    maxHP = hp;
    curHP = hp;
    scores[Ability::STR] = str;
    scores[Ability::DEX] = dex;
    scores[Ability::CON] = con;
    scores[Ability::INT] = intel;
    scores[Ability::WIS] = wis;
    scores[Ability::CHA] = cha;
    cr20 = dtrack::util::d20();
    calcMods();
    calcProficiency();
    formatDamage();
}

void Creature::calcMods() {
    for (int ab = (int) Ability::STR; ab < (int) Ability::CHA; ab++) {
        double dMod = (scores[(Ability) ab] - 10) / 2.0;
        int mod;
        if (dMod < 0) {
            mod = floor(dMod);
        } else {
            mod = dMod;
        }
        mods[(Ability) ab] = mod;
    }
}

void Creature::calcProficiency() {
    if(level >= 1) {
        prof = ceil((level / 4.0) - .1) + 1;
    } else {
        prof = 2;
    }
}

void Creature::formatDamage() {
    for (int ab = (int) Damage ::ACID; ab < (int) Damage::THUNDER; ab++) {
        damageInv[(Damage) ab] = false;
        damageRes[(Damage) ab] = false;
        damageVul[(Damage) ab] = false;
    }
}

int Creature::rollInitiative() {
    init = cr20.roll() + scores[Ability::DEX];
    return init;
}

int Creature::getScore(dtrack::entity::Ability abil) {
    return scores[abil];
}

int Creature::getMod(dtrack::entity::Ability abil) {
    return mods[abil];
}

//void Creature::giveAttack(std::string name, Attack attack) {
//    atks[name];
//}

//void Creature::attack(std::string attackName, dtrack::entity::Creature target, bool print) {
//    int dmg = atks[attackName].rollDamage();
//    target.damage(atks[attackName].damageType(), dmg);
//}

void Creature::damage(dtrack::entity::Damage dmg, int amt) {
    if(curHP > 0) {
        if (damageInv[dmg]) {
        } else if (damageRes[dmg]) {
            curHP -= amt / 2;
        } else if (damageVul[dmg]) {
            curHP -= amt * 2;
        } else {
            curHP -= amt;
        }

        if(curHP < 0) {
            curHP = 0;
        }
    }
}

void Creature::printToConsole(bool health) {
    double hp = (double)curHP/maxHP;
    if(hp == 1.0) {
        dtrack::util::ANSI::printUnderlinedColor(name,
                                                 dtrack::util::ANSI::Color::BR_GREEN,
                                                 false);
    } else if(hp > (2.0/3.0)) {
        dtrack::util::ANSI::printColor(name,
                                       dtrack::util::ANSI::Color::BR_GREEN,
                                       false);
    } else if(hp > (1.0/3.0)) {
        dtrack::util::ANSI::printColor(name,
                                       dtrack::util::ANSI::Color::BR_YELLOW,
                                       false);
    } else if(hp > 0) {
        dtrack::util::ANSI::printColor(name,
                                       dtrack::util::ANSI::Color::BR_RED,
                                       false);
    } else {
        dtrack::util::ANSI::printUnderlinedColor(name,
                                       dtrack::util::ANSI::Color::BR_BLACK,
                                       false);
    }
    if(health) {
        std::cout << " [" << curHP << "/" << maxHP << "]";
    }
    std::cout << "\n";
}
