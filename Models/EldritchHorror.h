//
// Created by emmik on 05/03/2021.
//

#ifndef FORC_PA_4_ELDRITCHHORROR_H
#define FORC_PA_4_ELDRITCHHORROR_H


#include "Creature.h"
#include "iostream"

class EldritchHorror: public Creature{

public:
    EldritchHorror(const int* traumatism, int* life, int* strength, int* intelligence);

    int get_traumatism();

    void set_traumatism(int* traumatism);

    friend std::ostream& operator<< (std::ostream& out, EldritchHorror* eldritchHorror);

private:
    int traumatism;
};


#endif //FORC_PA_4_ELDRITCHHORROR_H
