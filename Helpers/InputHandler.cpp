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
    this->file_handler = new FileHandler();


    // Roster
    this->DHInvestigators = new DataHandler<Investigator>;
    this->DHPersons = new DataHandler<Person>;
    this->DHCreatures = new DataHandler<Creature>;
    this->DHEldritchHorrors = new DataHandler<EldritchHorror>;

    // Templates
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
    delete this->file_handler;
    delete this->payload;

    this->individual_creator = nullptr;
    this->DHInvestigators = nullptr;
    this->DHPersons = nullptr;
    this->DHCreatures = nullptr;
    this->DHEldritchHorrors = nullptr;
    this->DHSpecies = nullptr;
    this->DHRoles = nullptr;
    this->file_handler = nullptr;
    this->payload = nullptr;
}

void InputHandler::main_menu() {
    int choice;
    string filename;
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
                cout << "Enter the filename of the new roster: ";
                cin >> filename;
                this->file_handler->save_roster(this->payload, new string(filename));
                break;
            case 4:
                cout << "Enter the filename of the roster you want to load: ";
                cin >> filename;
                this->file_handler->load_roster(this->payload, new string(filename));
                break;
            case 5:
                this->file_handler->save_templates(this->payload);
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
    while(true){
        cout << "1. View individuals\n2. Create individual\n3. Back" << endl;
        cin >> choice;
        switch (choice) {
            case(1):
                this->view_individuals();
                break;
            case(2):
                this->select_template_for_individual();
                break;
            case(3):
                return;
            default:
                cout << choice << " is not an option" << endl;
        }
    }
}

void InputHandler::select_template_for_individual() {
    this->view_shortened_templates();
    string name;
    cout << "Enter the name of the template you want to view." << endl;
    cin >> name;
    auto species_index = this->get_index_species(name);
    auto role_index = this->get_index_roles(name);
    if (role_index == -1 && species_index == -1) {
        cout << name << " does not exist!" << endl;
    } else {
        this->view_single_template(species_index, role_index);
    }
    cout << "1. Create Individual based on this template\n2. Return" << endl;
    int choice = 0;
    cin >> choice;
    switch (choice) {
        case 1:
            if (species_index >= 0) {
                auto species = this->DHSpecies->get_data()->at(species_index);
                if (species->get_is_eldritch()){
                    auto new_eldritch_horror = individual_creator->createEldritchHorror(species);
                    new_eldritch_horror->set_is_investigator(new bool(false));
                    this->DHEldritchHorrors->get_data()->push_back(new_eldritch_horror);
                    cout << new_eldritch_horror << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                    cin >> choice;
                    if(choice == 1){
                        new_eldritch_horror->edit();
                    }
                }
                else {
                    auto new_creature = individual_creator->createCreature(species);
                    new_creature->set_is_investigator(new bool(false));
                    this->DHCreatures->get_data()->push_back(new_creature);
                    cout << new_creature << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                    cin >> choice;
                    if(choice == 1){
                        new_creature->edit();
                    }
                }

            } else if (role_index >= 0) {
                auto role = this->DHRoles->get_data()->at(role_index);
                cout << "1. Investigator (playable character)\n2. Person (NPC)\n3. Return" << endl;
                cin >> choice;
                if (choice == 1){
                    auto new_investigator = individual_creator->createInvestigator(role);
                    new_investigator->set_is_investigator(new bool(true));
                    this->DHInvestigators->get_data()->push_back(new_investigator);
                    cout << new_investigator << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                    cin >> choice;
                    if(choice == 1){
                        new_investigator->edit();
                    }
                    auto_save();

                }
                else if (choice == 2){
                    auto new_person = individual_creator->createPerson(role);
                    new_person->set_is_investigator(new bool(false));
                    this->DHPersons->get_data()->push_back(new_person);
                    cout << new_person << endl << "Do you wish to edit this individual?\n1. yes\n2. no" << endl;
                    cin >> choice;
                    if(choice == 1){
                        new_person->edit();
                    }
                    auto_save();
                }
            }
        case 2:
            return;
    }
//
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
        cout << "Select a character type" << std::endl;
        cout << "1. Investigator" << endl;
        cout << "2. Person (NPC)" << endl;
        cout << "3. Creature" << endl;
        cout << "4. Eldritch Horror" << endl;
        cout << "5. Back" << std::endl;
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

void InputHandler::view_all_individuals() const {
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

void InputHandler::view_individuals() {
    int choice;
    while(true){
        cout << "1. View all individuals\n2. View by category\n3. Back" << endl;
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

void InputHandler::delete_template(){
    string name;
    this->view_shortened_templates();
    cout << "Enter the name of the template you want deleted." << endl;
    cin >> name;
    auto species_index = this->get_index_species(name);
    auto role_index = this->get_index_roles(name);
    if(role_index == -1 && species_index == -1){
        cout << name << " does not exist!" << endl;
    }
    else{
        if(species_index != -1){
            this->DHSpecies->get_data()->erase(this->DHSpecies->get_data()->begin() + species_index);
        }

        if(role_index != -1){
            this->DHRoles->get_data()->erase(this->DHRoles->get_data()->begin() + role_index);
        }
    }
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

void InputHandler::auto_save(){
    this->file_handler->save_roster(this->payload, new string("../roster_backup.txt"));
}