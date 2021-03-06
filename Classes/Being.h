//
// Created by emmik on 05/03/2021.
//

#ifndef FORC_PA_4_BEING_H
#define FORC_PA_4_BEING_H

#include "iostream"


class Being {
public:
    Being(int* life, int* strength, int* intelligence);

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