#ifndef FORC_PA_4_INPUTHANDLER_H
#define FORC_PA_4_INPUTHANDLER_H
#include "vector"
#include "iostream"
#include "fstream"

#include "../Models/Investigator.h"
#include "../Models/Person.h"
#include "../Models/Creature.h"
#include "../Models/EldritchHorror.h"
#include "../Classes/IndividualCreator.h"
#include "../Classes/TemplateCreator.h"
#include "DataHandler.h"
#include "../Templates/Role.h"
#include "../Templates/Species.h"


using namespace std;
class InputHandler {

public:
    InputHandler();
    ~InputHandler();

    IndividualCreator* individual_creator;

    DataHandler<Investigator>* DHInvestigators;
    DataHandler<Person>* DHPersons;
    DataHandler<Creature>* DHCreatures;
    DataHandler<EldritchHorror>* DHEldritchHorrors;
    DataHandler<Species>* DHSpecies;
    DataHandler<Role>* DHRoles;

    void displayCharacterTypes();
    void main_menu();
    void auto_save();

private:
    void individual_menu();
    void create_individual();
    void view_individuals();
    void view_all_individuals();
    void view_investigators();

    void template_menu();
    void create_template();
    void view_templates();
    void edit_templates();
    void delete_template();

};


#endif //FORC_PA_4_INPUTHANDLER_H
