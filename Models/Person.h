#ifndef FORC_PA_4_PERSON_H
#define FORC_PA_4_PERSON_H


#include "Being.h"
#include "string"
#include "iostream"
#include "../Helpers/HelperFunctions.h"
#include "../Templates/Role.h"

class Person: public Being {
public:
    Person(std::string* gender, int* fear, int* life, int* strength, int* intelligence);

    std::string get_gender();
    void set_gender(std::string* gender);

    int get_fear();
    void set_fear(int* fear);

    friend std::ostream& operator<< (std::ostream& out, Person* person);

private:
    std::string gender;
    int fear;
};


#endif //FORC_PA_4_PERSON_H
