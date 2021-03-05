#include <iostream>
#include "Classes/Investigator.h"
#include "Classes/EldritchHorror.h"
#include "Classes/Creature.h"
#include "Classes/Person.h"
#include "string"



using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;

    int terror = 6;
    std::string gender = "male";
    int fear = 5;
    int life = 4;
    int strength = 3;
    int intelligence = 2;
    int trauma = 1;
    bool unnatural = true;
    int disquiet = 1;


    auto new_investigator = new Investigator(&terror, &gender, &fear, &life, &strength, &intelligence);
    auto new_eldritch_the_richard = new EldritchHorror(&trauma, &life, &strength, &intelligence);
    auto new_emil = new Creature(&unnatural, &disquiet, &life, &strength, &intelligence);
    //std::string* gender, int* fear, int* life, int* strength, int* intelligence)
    auto new_person = new Person(&gender, &fear, &life, &strength, &intelligence);


    cout << "New investigator: \n" << new_investigator << endl;
    cout << "new eldritch richard:\n" << new_eldritch_the_richard << endl;
    cout << "new emil creature: \n" << new_emil << endl;
    cout << "new person: \n" << new_person << endl;

    return 0;
}
