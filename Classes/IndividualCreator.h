#ifndef FORC_PA_4_INDIVIDUALCREATOR_H
#define FORC_PA_4_INDIVIDUALCREATOR_H

#include <random>
#include "../Models/Investigator.h"
#include "../Models/EldritchHorror.h"
#include "../Models/Creature.h"
#include "../Models/Person.h"
#include "../Models/Being.h"
#include "../Helpers/HelperFunctions.h"

class IndividualCreator {
public:

    IndividualCreator();
    ~IndividualCreator();

    Person* createPerson();
    Investigator* createInvestigator();
    Creature* createCreature();
    EldritchHorror* createEldritchHorror();

private:
    std::string* gender_picker();
    void base_stat_generator();

    const int base_stat_count = 3;
    int* base_stats;
};

#endif //FORC_PA_4_INDIVIDUALCREATOR_H