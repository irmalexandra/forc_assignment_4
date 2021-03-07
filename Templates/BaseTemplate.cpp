#include "BaseTemplate.h"
#include "iostream"

BaseTemplate::BaseTemplate(int* life_min, int* life_max, int* strength_min, int* strength_max, int* intelligence_min, int* intelligence_max){
    this->life_min = *life_min;
    this->life_max = *life_max;
    this->intelligence_min = *intelligence_min;
    this->intelligence_max = *intelligence_max;
    this->strength_min = *strength_min;
    this->strength_max = *strength_max;
}

int BaseTemplate::get_life_range() {
    return this->life_max - this->life_min;
}

int BaseTemplate::get_intelligence_range() {
    return this->intelligence_max - this->intelligence_min;
}

int BaseTemplate::get_strength_range() {
    return this->strength_max - this->strength_min;
}

void BaseTemplate::set_life_range(int* life_min, int* life_max) {
    this->life_min = *life_min;
    this->life_max = *life_max;
}

void BaseTemplate::set_intelligence_range(int* intelligence_min, int* intelligence_max) {
    this->intelligence_min = *intelligence_min;
    this->intelligence_max = *intelligence_max;
}

void BaseTemplate::set_strength_range(int* strength_min, int* strength_max) {
    this->strength_min = *strength_min;
    this->strength_max = *strength_max;
}

std::ostream& operator<< (std::ostream& out, BaseTemplate* BaseTemplate) {
    out << "Life: " << BaseTemplate->get_life() << std::endl;
    out << "Strength: " << BaseTemplate->get_strength() << std::endl;
    out << "Intelligence: " << BaseTemplate->get_intelligence() << std::endl;
    return out;
}

