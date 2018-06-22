//
// Created by dylan on 6/17/2018.
//

#ifndef DUNGEONTRACKER_DIE_H
#define DUNGEONTRACKER_DIE_H

namespace dtrack::util {
    class Die {
    protected:
        int sides;
        double avg;
    public:
        Die(int sides);
        int roll();
        int roll(int times);
        double getAverage();
    };

    class d4 : public Die {
    public:
        d4() : Die(4) {};
    };

    class d6 : public Die {
    public:
        d6() : Die(6) {};
    };

    class d8 : public Die {
    public:
        d8() : Die(8) {};
    };

    class d10 : public Die {
    public:
        d10() : Die(10) {};
    };

    class d12 : public Die {
    public:
        d12() : Die(12) {};
    };

    class d20 : public Die {
    public:
        d20() : Die(20) {};
    };

    class d100 : public Die {
    public:
        d100() : Die(100) {};
    };
}


#endif //DUNGEONTRACKER_DIE_H
