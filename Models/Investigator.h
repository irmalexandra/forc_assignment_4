#ifndef FORC_PA_4_INVESTIGATOR_H
#define FORC_PA_4_INVESTIGATOR_H


#include "Person.h"
#include "iostream"
#include "../Templates/Role.h"

class Investigator: public Person {
public:
    Investigator(int* terror, std::string* gender, int* fear, int* life, int* strength, int* intelligence);
    int get_terror();
    void set_terror(int* terror);

    friend std::ostream& operator<< (std::ostream& out, Investigator* investigator);

private:
    int terror;
};


#endif //FORC_PA_4_INVESTIGATOR_H
