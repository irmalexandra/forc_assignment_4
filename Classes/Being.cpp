//
// Created by emmik on 05/03/2021.
//

#include "Being.h"
#include "iostream"

Being::Being(int* life, int* strength, int* intelligence){
    this->life = *life;
    this->strength = *strength;
    this->intelligence = *intelligence;
}

int Being::get_life() {
    return this->life;
}

int Being::get_intelligence() {
    return this->intelligence;
}

int Being::get_strength() {
    return this->strength;
}



void Being::set_life(int* life) {
    this->life = *life;
}

void Being::set_intelligence(int* intelligence) {
    this->intelligence = *intelligence;
}

void Being::set_strength(int* strength) {
    this->strength = *strength;
}

std::ostream& operator<< (std::ostream& out, Being* being) {
    out << "Life: " << being->get_life() << std::endl;
    out << "Strength: " << being->get_strength() << std::endl;
    out << "Intelligence: " << being->get_intelligence() << std::endl;
    return out;
}

