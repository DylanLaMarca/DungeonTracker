//
// Created by dylan on 6/17/2018.
//

#ifndef DUNGEONTRACKER_ATTACK_H
#define DUNGEONTRACKER_ATTACK_H

#include "Dice.h"
#include <map>

namespace dtrack::entity {
    enum class Damage { ACID, BLUDGEONING, COLD, FIRE, FORCE, LIGHTNING, NECROTIC, PIERCING, POISON,
            PSYCHIC, RADIANT, SLASHING, THUNDER};

    static std::map<Damage, std::string> damageNames = {{Damage::ACID, "Acid"}, {Damage::BLUDGEONING, "Bludgeoning"},
                                                              {Damage::COLD, "Cold"}, {Damage::FIRE, "Fire"},
                                                              {Damage::FORCE, "Force"}, {Damage::LIGHTNING, "Lightning"},
                                                              {Damage::NECROTIC, "Necrotic"}, {Damage::PIERCING, "Piercing"},
                                                              {Damage::POISON, "Poison"}, {Damage::PSYCHIC, "Psychic"},
                                                              {Damage::RADIANT, "Radiant"}, {Damage::SLASHING, "Slashing"},
                                                              {Damage::THUNDER, "Thunder"}};

    static void printDamage(Damage dmg);

    class Attack {
    private:
        Damage type;
        int dieNum;
        dtrack::util::Die die;
        int modBonus;
    public:
        Attack(Damage dmg, int dieSides, int num, int bonus);
        int rollDamage();
        Damage damageType();
    };
}


#endif //DUNGEONTRACKER_ATTACK_H
