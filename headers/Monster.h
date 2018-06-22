#ifndef DUNGEONTRACKER_MONSTER_H
#define DUNGEONTRACKER_MONSTER_H

#include "Creature.h"

namespace dtrack::entity {
    class Monster : public Creature {
    public:
        Monster(std::string filename) : Creature() {};
    };
}


#endif //DUNGEONTRACKER_MONSTER_H
