//
// Created by emmik on 05/03/2021.
//

#include "InputHandler.h"
#include "iostream"
#include "CharacterCreator.h"


void InputHandler::createCharacter() {
    Investigator* investigator = nullptr;
    Person* person = nullptr;
    Creature* creature = nullptr;
    EldritchHorror* eldritch_horror = nullptr;

    std::cout << "Select a character type" << std::endl;
    std::cout << "1. Investigator" << std::endl;
    std::cout << "2. Person" << std::endl;
    std::cout << "3. Creature" << std::endl;
    std::cout << "4. Eldritch Horror" << std::endl;

    int choice = 0;
    std::cin >> choice;
    switch (choice) {
        case 1:
            investigator = CharacterCreator::createInvestigator();
            break;
        case 2:
            person = CharacterCreator::createPerson();
            break;
        case 3:
            creature = CharacterCreator::createCreature();
            break;
        case 4:
            eldritch_horror = CharacterCreator::createEldritchHorror();
            break;
        default:
            std::cout << "Invalid selection" << std::endl;
            break;
    }

}