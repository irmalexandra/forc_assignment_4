//
// Created by emmik on 05/03/2021.
//

#include "CharacterCreator.h"


std::string *CharacterCreator::gender_picker() {
    int choice;


    std::cout << "Pick a gender:\n1. male\n2. female\n3. non-binary"<< std::endl;
    enum Gender { Male, Female, Non_Binary };
    Gender gender = Non_Binary;
    std::cin >> choice;
    switch (choice) {
        case 1:
            gender = Male;
            break;
        case 2:
            gender = Female;
            break;
        case 3:
            gender = Non_Binary;
            break;
        default:
            std::cout << choice << " is not a valid option";
   }
    switch (gender) {
        case Male:
            return new std::string("Male");
            break;
        case Female:
            return new std::string("Female");
            break;
        case Non_Binary:
            return new std::string("Non-Binary");
            break;
    }
}

Person *CharacterCreator::createPerson() {
    // std::string* gender, int* fear, int* life, int* strength, int* intelligence)
    std::string* gender = this->gender_picker();
    int* fear;
    int* life;
    int* strength;
    int* intelligence;
    int choice;





    return nullptr;
}

Investigator *CharacterCreator::createInvestigator() {
    //int* terror, std::string* gender, int* fear, int* life, int* strength, int* intelligence
    return nullptr;
}

Creature *CharacterCreator::createCreature() {
    //(bool* unnatural, int* disquiet, int* life, int* strength, int* intelligence)
    return nullptr;
}

EldritchHorror *CharacterCreator::createEldritchHorror() {
    // const int* traumatism, int* life, int* strength, int* intelligence)
    return nullptr;
}

