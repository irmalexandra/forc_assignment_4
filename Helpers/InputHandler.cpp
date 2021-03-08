#include "InputHandler.h"

bool create_another_character(){
    cout << "Create another? (y/n)" << endl;
    char choice = 'y';
    cin >> choice;
    return choice == 'y';
}

void InputHandler::auto_save(){
    string filename = "../Resources/data.txt";
    ofstream fileout(filename, ios::trunc);

    fileout << this->DHSpecies->get_data()->size() << endl;
    fileout << this->DHSpecies;
    fileout << "***" << endl;
    fileout << this->DHRoles->get_data()->size() << endl;
    fileout << this->DHRoles;
}

InputHandler::InputHandler() {
    this->individual_creator = new IndividualCreator();
    this->template_creator = new TemplateCreator();
    this->DHInvestigators = new DataHandler<Investigator>;
    this->DHPersons = new DataHandler<Person>;
    this->DHCreatures = new DataHandler<Creature>;
    this->DHEldritchHorrors = new DataHandler<EldritchHorror>;
    this->DHSpecies = new DataHandler<Species>;
    this->DHRoles = new DataHandler<Role>;

}

InputHandler::~InputHandler() {
    delete this->individual_creator;
    delete this->DHInvestigators;
    delete this->DHCreatures;
    delete this->DHEldritchHorrors;
    delete this->DHPersons;
    delete this->DHSpecies;
    delete this->DHRoles;

    this->individual_creator = nullptr;
    this->DHInvestigators = nullptr;
    this->DHPersons = nullptr;
    this->DHCreatures = nullptr;
    this->DHEldritchHorrors = nullptr;
    this->DHSpecies = nullptr;
    this->DHRoles = nullptr;
}

void InputHandler::create_individual() {
    Investigator* investigator;
    Person* person;
    Creature* creature;
    EldritchHorror* eldritch_horror;

    bool create_process = true;



    int choice = 0;
    while (create_process){
        this->displayCharacterTypes();
        std::cin >> choice;
        switch (choice) {
            case 1:
                investigator = this->individual_creator->createInvestigator();
                this->DHInvestigators->get_data()->push_back(investigator);
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

void InputHandler::create_template() {
    int choice = 0;
    bool create_process = true;

    Species* species;
    Role* role;


    while(create_process){
        std::cout << "Select:" << std::endl;
        std::cout << "1. Species" << std::endl;
        std::cout << "2. Role" << std::endl;
       cin >> choice;
       switch (choice) {
           case 1:
               species = this->template_creator->create_species();
               this->DHSpecies->get_data()->push_back(species);
               break;
           case 2:
               role = this->template_creator->create_role();
               this->DHRoles->get_data()->push_back(role);
               break;
           default:
               cout << "Invalid selection: " << choice << endl;
               break;

       }
        this->auto_save();
        create_process = create_another_character();
    }



}

void InputHandler::displayCharacterTypes() {
    std::cout << "Select a character type" << std::endl;
    std::cout << "1. Investigator" << std::endl;
    std::cout << "2. Person (NPC)" << std::endl;
    std::cout << "3. Creature" << std::endl;
    std::cout << "4. Eldritch Horror" << std::endl;
    std::cout << "5. Quit" << std::endl;
    int choice;

    while(true){
        cin >> choice;
        switch(choice){
            case 1:
                cout << this->DHInvestigators << endl;
                break;
            case 2:
                cout << this->DHPersons << endl;
                break;
            case 3:
                cout << this->DHCreatures << endl;
                break;
            case 4:
                cout << this->DHEldritchHorrors << endl;
                break;
            case 5:
                return;
            default:
                cout<<"Error"<<endl;
        }
    }


}

void InputHandler::main_menu() {
    int choice;
    while(true){
        cout << "1. Templates\n2. Individuals\n3. quit" << endl;
        cin >> choice;
        switch (choice) {
            case(1):
                this->template_menu();
                break;
            case(2):
                this->individual_menu();
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
        }
    }


}

void InputHandler::template_menu() {
    int choice;
    while(true){
        cout << "1. View templates\n2. Edit templates\n3. Back" << endl;
        cin >> choice;
        switch (choice) {
            case(1):
                this->view_templates();
                break;
            case(2):
                this->edit_templates();
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
        }
    }
}

void InputHandler::individual_menu() {
    int choice;
    cout << "1. View individuals\n2. Create individual\n3. Back" << endl;

    while(true){
        cin >> choice;
        switch (choice) {
            case(1):
                this->view_individuals();
                break;
            case(2):
                this->create_individual();
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
        }
    }
}

void InputHandler::view_templates() {
    cout << "Available Roles" << endl;
    cout << DHRoles << endl;
    cout << "\nAvailable Species" << endl;
    cout << DHSpecies << endl;

}

void InputHandler::edit_templates() {
    int choice;
    while(true){
        cout << "1. Create templates\n2. Delete template\n3. Back" << endl;
        cin >> choice;
        switch (choice) {
            case(1):
                this->create_template();
                break;
            case(2):
                this->delete_template();
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
        }
    }
}


void InputHandler::view_individuals() {
    int choice;
    while(true){
        cout << "1. View all individuals\n2. View investigators\n3. Back" << endl;
        cin >> choice;
        switch (choice) {
            case(1):
                this->view_all_individuals();
                break;
            case(2):
                this->view_investigators();
                this->auto_save();
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
        }
    }
}

void InputHandler::view_all_individuals() {
    cout << "Created individuals\n" << endl;
    cout << "Investigators:" << endl;
    cout << this->DHInvestigators << endl;
    cout << "\nNPCs:" << endl;
    cout << this->DHPersons << endl;
    cout << "\nCreatures:" << endl;
    cout << this->DHCreatures << endl;
    cout << "\nEldritch Horrors" << endl;
    cout << this->DHEldritchHorrors << endl;

}

void InputHandler::view_investigators() {
    // print only investigators
}

void InputHandler::delete_template() {

}








