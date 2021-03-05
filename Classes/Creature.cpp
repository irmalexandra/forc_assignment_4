//
// Created by emmik on 05/03/2021.
//

#include "Creature.h"

Creature::Creature(bool* unnatural, int* disquiet, int* life, int* strength, int* intelligence): Being(life, strength, intelligence){
    this->unnatural = *unnatural;
    this->disquiet = *disquiet;
}

bool Creature::get_unnatural() {
    return this->unnatural;
}

int Creature::get_disquiet() {
    return this->disquiet;
}

void Creature::set_unnatural(bool* unnatural) {
    this->unnatural = *unnatural;
}

void Creature::set_disquiet(int *disquiet) {
    this->disquiet = *disquiet;
}

std::ostream& operator<< (std::ostream& out, Creature* creature){
    out << (Being*)(creature);
    out << "Unnatural: " << creature->get_unnatural() << std::endl;
    out << "Disquiet: " << creature->get_disquiet() << std::endl;
    return out;
};
