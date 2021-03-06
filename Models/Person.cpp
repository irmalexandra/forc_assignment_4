//
// Created by emmik on 05/03/2021.
//

#include "Person.h"

Person::Person(std::string* gender, int* fear, int* life, int* strength, int* intelligence): Being(life, strength, intelligence){
    this->gender = *gender;
    this->fear = *fear;

    delete gender;
    gender = nullptr;
}

std::string Person::get_gender() {
    return this->gender;
}

void Person::set_gender(std::string *gender) {
    this->gender = *gender;
}

int Person::get_fear() {
    return this->fear;
}

void Person::set_fear(int *fear) {
    this->fear = *fear;
}

std::ostream& operator<< (std::ostream& out, Person* person) {
    out << (Being*)(person);
    out << "Gender: " << person->get_gender() << std::endl;
    out << "Fear: " << person->get_fear() << std::endl;
    return out;
}

