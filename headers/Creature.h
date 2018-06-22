//
// Created by dylan on 6/17/2018.
//

#ifndef DUNGEONTRACKER_CREATURE_H
#define DUNGEONTRACKER_CREATURE_H

#include <string>
#include <map>

#include "ANSI.h"
#include "Dice.h"
#include "Attack.h"
#include "CreatureElements.h"
#include "Alignment.h"

namespace dtrack::entity {

    class Creature {
    protected:
        std::string name;
        int maxHP;
        int curHP;
        int init;
        int level;
        int prof;
        Alignment alignment;
        std::map<Damage, bool> damageRes;
        std::map<Damage, bool> damageInv;
        std::map<Damage, bool> damageVul;
        std::map<Ability, int> scores;
        std::map<Ability, int> mods;
        std::map<Skill, int> bonuses;
        std::map<std::string, Attack> atks;
        dtrack::util::d20 cr20;
//        dtrack::util::Die hitDie;

        void calcMods();
        void calcProficiency();
        void formatDamage();

        Creature();
    public:
        Creature(std::string name, int level, int hp, int str, int dex, int con, int intel, int wis, int cha);
        int rollInitiative();
        int getScore(Ability abil);
        int getMod(Ability abil);
        void damage(Damage dmg, int amt);
        void giveLanguage(Language lang);
        void giveLanguage(std::string lang);
//        void giveAttack(std::string name, Attack attack);
//        void attack(std::string attack, Creature target, bool print);
        void printToConsole(bool health);
    };
}


#endif //DUNGEONTRACKER_CREATURE_H
