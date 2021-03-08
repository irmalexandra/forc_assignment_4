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
#include "Helpers/FileHandler.h"



using namespace std;
int main() {
    auto input_handler = InputHandler();

    auto file_handler = FileHandler();

    file_handler.make_templates_list("../Resources/data.txt", input_handler);

    input_handler.main_menu();

    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));



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
//    input_handler->create_individual();
//    input_handler->data_handler->display_data();

    return 0;
}
