#include "IndividualCreator.h"

IndividualCreator::IndividualCreator(){
    this->base_stats = new int[this->base_stat_count];
}

IndividualCreator::~IndividualCreator() {
    delete this->base_stats;
    this->base_stats = nullptr;
}

std::string *IndividualCreator::gender_picker() {
    int choice;
    std::cout << "Pick a gender:\n1. Male\n2. Female\n3. Other"<< std::endl;
    enum Gender { Male = 1, Female = 2, Other = 3};
    while(true){
        std::cin >> choice;
        switch (choice) {
            case Male:
                return new std::string("Male");
            case Female:
                return new std::string("Female");
            case Other:
                return new std::string("Other");
            default:
                std::cout << choice << " is not a valid option";
        }
    }
}

void IndividualCreator::base_stat_generator(){

    for (int i = 0; i < IndividualCreator::base_stat_count; i++){
        base_stats[i] = int(rand() % 10);
    }
}

Person *IndividualCreator::createPerson() {
    IndividualCreator::base_stat_generator();
    std::string* gender = gender_picker();
    int fear = rand() % 10;
    return new Person(gender, &fear, &base_stats[0], &base_stats[1], &base_stats[2]);
}

Investigator *IndividualCreator::createInvestigator() {
    base_stat_generator();
    std::string* gender = gender_picker();
    int fear = rand() % 10;
    int terror = rand() % 3;
    return new Investigator(&terror, gender, &fear, &base_stats[0], &base_stats[1], &base_stats[2]);
}

Creature *IndividualCreator::createCreature() {
    base_stat_generator();
    bool unnatural = (bool)(rand() % 1);
    int disquiet = rand() % 10;
    return new Creature(&unnatural, &disquiet, &base_stats[0], &base_stats[1], &base_stats[2]);
}

EldritchHorror *IndividualCreator::createEldritchHorror() {
    base_stat_generator();
    int traumatism = rand() % 3;
    return new EldritchHorror(&traumatism, &base_stats[0], &base_stats[1], &base_stats[2]);
}



