//
// Created by dylan on 6/19/2018.
//

#ifndef DUNGEONTRACKER_CREATUREELEMENTS_H
#define DUNGEONTRACKER_CREATUREELEMENTS_H

using namespace std;

namespace dtrack::entity {
    enum class Ability {
        STR = 1, DEX = 2, CON = 3, INT = 4, WIS = 5, CHA = 6
    };
    enum class Skill {
        ATHLETICS = 1, ACROBATICS = 2, SLEIGHT_OF_HAND = 12, ARCANA = 4,
        HISTORY = 14, INVESTIGATION = 24, NATURE = 34, RELIGION = 44, ANIMAL_HANDLING = 5,
        INSIGHT = 15, MEDICINE = 25, PERCEPTION = 35, SURVIVAL = 45, DECEPTION = 6,
        INTIMIDATION = 16, PERFORMANCE = 26, PERSUATION = 36
    };
    enum class Language {
        ABYSSAL, AQUAN, AURAN, CELESTIAL, COMMON, DEEP_SPEECH, DRACONIC, DRUIDIC,
        DWARVISH, EAGLE, ELVISH, GIANT, GNOMISH, GOBLIN, GNOLL, HALFLING, INGAN, INFERNAL,
        ORC, PRIMORDIAL, SYLVAN, TERRAN, UNDERCOMMON
    };
    enum class MonsterType {
        ABERRATION, BEAST, CELESTIAL, CONSTRUCT, DRAGON, ELEMENTAL, FEY, FIEND,
        GIANT, HUMANOID, MONSTROCITY, OOZE, PLANT, UNDEAD
    };
    static map<MonsterType, string> monsterTypeToString = {{MonsterType::ABERRATION,"aberration"},
            {MonsterType::BEAST,"beast"},{MonsterType::CELESTIAL,"celestial"},
            {MonsterType::CONSTRUCT,"construct"},{MonsterType::DRAGON,"dragon"},
            {MonsterType::ELEMENTAL,"elemental"},{MonsterType::FEY,"fey"},{MonsterType::FIEND,"fiend"},
            {MonsterType::GIANT,"giant"},{MonsterType::HUMANOID,"humanoid"},
            {MonsterType::MONSTROCITY,"monstrocity"},{MonsterType::OOZE,"ooze"},
            {MonsterType::PLANT,"plant"},{MonsterType::UNDEAD,"undead"}};
    static map<string, MonsterType> stringToMonsterType = {{"aberration",MonsterType::ABERRATION},
           {"beast",MonsterType::BEAST},{"celestial",MonsterType::CELESTIAL},
           {"construct",MonsterType::CONSTRUCT},{"dragon",MonsterType::DRAGON},
           {"elemental",MonsterType::ELEMENTAL},{"fey",MonsterType::FEY},{"fiend",MonsterType::FIEND},
           {"giant",MonsterType::GIANT},{"humanoid",MonsterType::HUMANOID},
           {"monstrocity",MonsterType::MONSTROCITY},{"ooze",MonsterType::OOZE},
           {"plant",MonsterType::PLANT},{"undead",MonsterType::UNDEAD}};

    enum class Size { TINY, SMALL, MEDIUM, LARGE, HUGE, GARGANTUAN };
    static map<Size, string> sizeToString = {{Size::TINY,"tiny"},{Size::SMALL,"small"},
            {Size::MEDIUM,"medium"},{Size::LARGE,"large"},{Size::HUGE,"huge"},{Size::GARGANTUAN,"gargantuan"}};
    static map<string, Size> stringToSize = {{"tiny",Size::TINY},{"small",Size::SMALL},
            {"medium",Size::MEDIUM},{"large",Size::LARGE},{"huge",Size::HUGE},{"gargantuan",Size::GARGANTUAN}};
}

#endif //DUNGEONTRACKER_CREATUREELEMENTS_H
