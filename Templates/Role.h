
#ifndef FORC_PA_4_ROLE_H
#define FORC_PA_4_ROLE_H


#include "BaseTemplate.h"
#include "string"
#include "iostream"

class Role: public BaseTemplate {
public:
    Role(baseStats* base_stats);


    friend std::ostream& operator<< (std::ostream& out, Role* person);

};


#endif //FORC_PA_4_ROLE_H
