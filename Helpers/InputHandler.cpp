#include "InputHandler.h"


bool create_another_character(){
    cout << "Create another? (y/n)" << endl;
    char choice = 'y';
    cin >> choice;
    return choice == 'y';
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

    // Payload
    this->payload = new Payload(
            this->DHInvestigators,
            this->DHPersons,
            this->DHCreatures,
            this->DHEldritchHorrors,
            this->DHSpecies,
            this->DHRoles);

    this->file_handler->load_templates(this->payload);
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

void InputHandler::main_menu() {
    int choice;
    while(true){
        cout << "1. Templates\n2. Individuals\n3. Save current roster\n4. Load new roster\n5. Quit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                this->template_menu();
                break;
            case 2:
                this->individual_menu();
                break;
            case 3:
                this->file_handler->save_roster(this->payload, new string("../gofuckyourself.txt"));
                break;
            case 4:
                this->file_handler->load_roster(this->payload, new string("../gofuckyourselfagain.txt"));
                break;
            case 5:
                this->file_handler->save_templates(this->payload);
                return;
            default:
                cout << choice << " is not an option" << endl;
        }
    }
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
        create_process = create_another_character();
    }



}

void InputHandler::view_individuals_by_category() {

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

void InputHandler::view_templates() {
    cout << "Available Roles" << endl;
    cout << DHRoles << endl;
    cout << "\nAvailable Species" << endl;
    cout << DHSpecies << endl;

}

void InputHandler::view_single_template(int species_index, int role_index){

    if(species_index != -1){
        cout << this->DHSpecies->get_data()->at(species_index) << endl;
    }

    else if(role_index != -1){
        cout << this->DHRoles->get_data()->at(role_index) << endl;
    }
}

void InputHandler::view_shortened_templates(){
    cout << "Available Roles:" << endl;
    for(const auto role: *this->DHRoles->get_data()){
        cout << '\t' << role->get_name() << endl;
    }

    cout << "\nAvailable Species:" << endl;
    for(const auto species: *this->DHSpecies->get_data()){
        cout << '\t' << species->get_name() << endl;
    }
}

void InputHandler::view_shortened_individuals(){
    cout << "Individuals:" << endl << endl << "Persons(NPCs)" << endl;

    for(const auto individual: *this->DHPersons->get_data()){
        cout << '\t' << individual->get_name() << endl;
    }
    cout << "Investigators:" << endl;
    for(const auto individual: *this->DHInvestigators->get_data()){
        cout << '\t' << individual->get_name() << endl;
    }
    cout << "Creatures " << endl;
    for(const auto individual: *this->DHCreatures->get_data()){
        cout << '\t' << individual->get_name() << endl;
    }
    cout << "Eldritch Horrors" << endl;
    for(const auto individual: *this->DHEldritchHorrors->get_data()){
        cout << '\t' << individual->get_name() << endl;
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
                this->view_individuals_by_category();
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
        }
    }
}

void InputHandler::delete_template() {

}

int InputHandler::get_index_roles(const string& name) const{
    int index = -1;
    for (int i = 0; i < this->DHRoles->get_data()->size(); i++){
        if(this->DHRoles->get_data()->at(i)->get_name() == name){
            index = i;
            return index;
        }
    }
    return index;
}

int InputHandler::get_index_species(const string& name) const {
    int index = -1;
    for (int i = 0; i < this->DHSpecies->get_data()->size(); i++){
        if(this->DHSpecies->get_data()->at(i)->get_name() == name){
            index = i;
            return index;
        }
    }
    return index;
}
