#include "InputHandler.h"

bool create_another_character(){
    std::cout << "Create another character? (y/s)" << std::endl;
    char choice = 'y';
    std::cin >> choice;
    return choice == 'y';
}

InputHandler::InputHandler() {
    this->individual_creator = new IndividualCreator();
    this->DHInvestigator = new DataHandler<Investigator>;
    this->DHPersons= new DataHandler<Person>;
    this->DHCreatures = new DataHandler<Creature>;
    this->DHEldritchHorrors = new DataHandler<EldritchHorror>;
}

InputHandler::~InputHandler() {
    delete this->individual_creator;
    delete this->DHInvestigator;
    delete this->DHCreatures;
    delete this->DHCreatures;
    delete this->DHPersons;

    this->individual_creator = nullptr;
    this->DHInvestigator = nullptr;
    this->DHPersons = nullptr;
    this->DHCreatures = nullptr;
    this->DHEldritchHorrors = nullptr;
}

void InputHandler::createIndividual() {
    Investigator* investigator;
    Person* person;
    Creature* creature;
    EldritchHorror* eldritch_horror;

    bool create_process = true;

    this->displayCharacterTypes();

    int choice = 0;
    while (create_process){
        std::cin >> choice;
        switch (choice) {
            case 1:
                investigator = this->individual_creator->createInvestigator();
                this->DHInvestigator->get_data()->push_back(investigator);
                create_process = create_another_character();
                break;
            case 2:
                person = this->individual_creator->createPerson();
                this->DHPersons->get_data()->push_back(person);
                create_process = create_another_character();
                break;
            case 3:
                creature = this->individual_creator->createCreature();
                this->DHCreatures->get_data()->push_back(creature);
                create_process = create_another_character();
                break;
            case 4:
                eldritch_horror = this->individual_creator->createEldritchHorror();
                this->DHEldritchHorrors->get_data()->push_back(eldritch_horror);
                create_process = create_another_character();
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid selection: " << choice << std::endl;
                break;
        }
    }
}

void InputHandler::createTemplate() {

}

void InputHandler::displayCharacterTypes() {
    std::cout << "Select a character type" << std::endl;
    std::cout << "1. Investigator" << std::endl;
    std::cout << "2. Person (NPC)" << std::endl;
    std::cout << "3. Creature" << std::endl;
    std::cout << "4. Eldritch Horror" << std::endl;
    std::cout << "5. Quit" << std::endl;
}



