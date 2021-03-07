//
// Created by emmik on 05/03/2021.
//

#ifndef FORC_PA_4_PERSON_H
#define FORC_PA_4_ROLE_H


#include "Being.h"
#include "string"
#include "iostream"


class Role: public Being {
public:
    Role(int* fear, int* life_min, int* life_max,
         int* strength_min, int* strength_max, int* intelligence_min, int* intelligence_max);


    int get_fear();
    void set_fear(int* fear);

    friend std::ostream& operator<< (std::ostream& out, Person* person);

private:
    int fear;
};


#endif //FORC_PA_4_PERSON_H
