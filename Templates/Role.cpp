//
// Created by emmik on 05/03/2021.
//

#include "Role.h"

Role::Role(int* fear, int* life_min, int* life_max,
               int* strength_min, int* strength_max, int* intelligence_min, int* intelligence_max):
               Being(life_min, life_max, strength_min, strength_max, intelligence_min, intelligence_max){
    this->fear = *fear;
}

int Role::get_fear() {
    return this->fear;
}

void Role::set_fear(int *fear) {
    this->fear = *fear;
}

std::ostream& operator<< (std::ostream& out, Role* Role) {
    out << (Being*)(Role);
    out << "Fear: " << Role->get_fear() << std::endl;
    return out;
}

