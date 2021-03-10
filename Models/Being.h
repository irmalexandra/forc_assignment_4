#ifndef FORC_PA_4_BEING_H
#define FORC_PA_4_BEING_H

#include "iostream"
#include "../Helpers/HelperFunctions.h"
#include "../Templates/BaseTemplate.h"

class Being {
public:
    Being(BaseTemplate* base_template);
    Being(baseIndividualStats* stats);
//    ~Being();

    void edit();

    int get_life();
    int get_strength();
    int get_intelligence();
    std::string get_name();

    void set_name(std::string* name);
    void set_life(int* life);
    void set_strength(int* strength);
    void set_intelligence(int* intelligence);

    BaseTemplate* get_template();

    friend std::ostream& operator<< (std::ostream& out, Being* being);

protected:
    std::string name;

private:
    int life;
    int strength;
    int intelligence;

    BaseTemplate* base_template;
};


#endif //FORC_PA_4_BEING_H
