//
// Created by emmik on 05/03/2021.
//

#include "Investigator.h"


Investigator::Investigator(int* terror, std::string* gender, int* fear, int* life, int* strength, int* intelligence):
Person(gender, fear, life, strength, intelligence){
    this->terror = *terror;
}

int Investigator::get_terror() {
    return this->terror;
}

void Investigator::set_terror(int *terror) {
    this->terror = *terror;
}

std::ostream& operator<< (std::ostream& out, Investigator* investigator) {
    out << (Person*)(investigator);
    out << "Terror: " << investigator->get_terror() << std::endl;
    return out;
}