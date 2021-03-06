#include <iostream>
#include <random>
#include <chrono>

#include "Models/Investigator.h"
#include "Models/EldritchHorror.h"
#include "Models/Creature.h"
#include "Models/Person.h"
#include "Classes/IndividualCreator.h"
#include "string"
#include "Helpers/InputHandler.h"



using namespace std;
int main() {
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int* choice = new int;

    cout << "1. Templates\n2. Individuals\3. quit" << endl;
    cin >> *choice;
    switch (*choice) {
        case(1):

            break;
        case(2):
            break;
        case(3):
            return 0;
        default:
            cout << "no" << endl;

    }


//    std::cout << "Hello, World!" << std::endl;
//
//    int terror = 6;
//    std::string gender = "male";
//    int fear = 5;
//    int life = 4;
//    int strength = 3;
//    int intelligence = 2;
//    int trauma = 1;
//    bool unnatural = true;
//    int disquiet = 1;
//
//
////    auto new_investigator = new Investigator(&terror, &gender, &fear, &life, &strength, &intelligence);
////    auto new_eldritch_the_richard = new EldritchHorror(&trauma, &life, &strength, &intelligence);
////    auto new_emil = new Creature(&unnatural, &disquiet, &life, &strength, &intelligence);
////    //std::string* gender, int* fear, int* life, int* strength, int* intelligence)
////    auto new_person = new Person(&gender, &fear, &life, &strength, &intelligence);
////
//
////    auto new_investigator = new Investigator(&terror, &gender, &fear, &life, &strength, &intelligence);
////    auto new_eldritch_the_richard = new EldritchHorror(&trauma, &life, &strength, &intelligence);
////    auto new_emil = new Creature(&unnatural, &disquiet, &life, &strength, &intelligence);
////    //std::string* gender, int* fear, int* life, int* strength, int* intelligence)
////    auto new_person = new Person(&gender, &fear, &life, &strength, &intelligence);
//
//
//    auto input_handler = new InputHandler();
//    input_handler->createIndividual();
//    input_handler->data_handler->display_data();

    return 0;
}
