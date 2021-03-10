#ifndef FORC_PA_4_BEING_H
#define FORC_PA_4_BEING_H

#include "iostream"
#include "../Helpers/HelperFunctions.h"
#include "../Templates/BaseTemplate.h"

class Being {
public:
    Being(int* life, int* strength, int* intelligence);
//    ~Being();

    int get_life();
    int get_strength();
    int get_intelligence();

    void set_life(int* life);
    void set_strength(int* strength);
    void set_intelligence(int* intelligence);

    friend std::ostream& operator<< (std::ostream& out, Being* being);
private:
    int life;
    int strength;
    int intelligence;
};


#endif //FORC_PA_4_BEING_H
