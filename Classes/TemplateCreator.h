#ifndef FORC_PA_4_TEMPLATECREATOR_H
#define FORC_PA_4_TEMPLATECREATOR_H

#include "iostream"
#include "../Templates/Role.h"
#include "../Templates/Species.h"

using namespace std;

class TemplateCreator {
public:
    TemplateCreator();
    ~TemplateCreator();

    Role* createRole();
    Species* createSpecies();

private:
    std::string* gender_picker();
    void base_stat_setter();

    const int base_stat_count = 3;
};


#endif //FORC_PA_4_TEMPLATECREATOR_H
