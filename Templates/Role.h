//
// Created by emmik on 05/03/2021.
//

#ifndef FORC_PA_4_PERSON_H
#define FORC_PA_4_ROLE_H


#include "Being.h"
#include "string"
#include "iostream"


class Role: public BaseTemplate {
public:
    Role(int* fear, int* life_min, int* life_max,
         int* strength_min, int* strength_max, int* intelligence_min, int* intelligence_max);


    friend std::ostream& operator<< (std::ostream& out, Role* person);

};


#endif //FORC_PA_4_PERSON_H
