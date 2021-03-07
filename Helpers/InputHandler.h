#ifndef FORC_PA_4_INPUTHANDLER_H
#define FORC_PA_4_INPUTHANDLER_H
#include "vector"
#include "iostream"

#include "../Models/Investigator.h"
#include "../Models/Person.h"
#include "../Models/Creature.h"
#include "../Models/EldritchHorror.h"
#include "../Classes/IndividualCreator.h"
#include "DataHandler.h"


class InputHandler {

public:
    InputHandler();
    ~InputHandler();

    IndividualCreator* individual_creator;

    DataHandler<Investigator>* DHInvestigator;
    DataHandler<Person>* DHPersons;
    DataHandler<Creature>* DHCreatures;
    DataHandler<EldritchHorror>* DHEldritchHorrors;

    void createIndividual();
    void createTemplate();
    static void displayCharacterTypes();
    void saveCharacter();
    void loadCharacter();

};


#endif //FORC_PA_4_INPUTHANDLER_H
