#ifndef FORC_PA_4_DATAHANDLER_H
#define FORC_PA_4_DATAHANDLER_H
#include "vector"
#include "../Models/Investigator.h"
#include "../Models/Person.h"
#include "../Models/Creature.h"
#include "../Models/EldritchHorror.h"

#include "../Templates/Role.h"
#include "../Templates/Species.h"


template<typename T>
class DataHandler {
public:
    DataHandler();
    ~DataHandler();
    std::vector<T*>* get_data();
    void display_data();
private:
    std::vector<T*>* data;
};


#endif //FORC_PA_4_DATAHANDLER_H
