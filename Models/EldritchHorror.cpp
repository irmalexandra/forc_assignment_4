//
// Created by emmik on 05/03/2021.
//

#include "EldritchHorror.h"

EldritchHorror::EldritchHorror(const int* traumatism, int* life, int* strength, int* intelligence):
Creature((new bool(true)), (new int(10)), life, strength, intelligence)  {
    this->traumatism = *traumatism;
}

int EldritchHorror::get_traumatism() {
    return this->traumatism;
}

void EldritchHorror::set_traumatism(int *traumatism) {
    this->traumatism = *traumatism;
}

std::ostream& operator<< (std::ostream& out, EldritchHorror* eldritchHorror){
    out << (Creature*)(eldritchHorror);
    out << "Traumatism: " << eldritchHorror->get_traumatism() << std::endl;
    return out;
}
