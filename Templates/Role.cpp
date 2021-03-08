#include "Role.h"

Role::Role(int* fear, int* life_min, int* life_max,
               int* strength_min, int* strength_max, int* intelligence_min, int* intelligence_max):
               Being(life_min, life_max, strength_min, strength_max, intelligence_min, intelligence_max){
    this->fear = *fear;
}

std::ostream& operator<< (std::ostream& out, Role* Role) {
    out << (BaseTemplate*)(Role);
    return out;
}

