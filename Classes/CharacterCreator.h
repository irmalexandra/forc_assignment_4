//
// Created by emmik on 05/03/2021.
//


#ifndef FORC_PA_4_CHARACTERCREATOR_H
#define FORC_PA_4_CHARACTERCREATOR_H
#include "Investigator.h"
#include "EldritchHorror.h"
#include "Creature.h"
#include "Person.h"
#include "Being.h"

static class CharacterCreator {
public:
    static Person* createPerson();
    static Investigator* createInvestigator();
    static Creature* createCreature();
    static EldritchHorror* createEldritchHorror();

private:
    std::string* gender_picker();
};


#endif //FORC_PA_4_CHARACTERCREATOR_H
