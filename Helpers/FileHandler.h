#ifndef FORC_PA_4_FILEHANDLER_H
#define FORC_PA_4_FILEHANDLER_H
#include <random>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

#include "../Templates/BaseTemplate.h"
#include "../Templates/Role.h"
#include "../Templates/Species.h"
#include "../Helpers/HelperFunctions.h"
#include "InputHandler.h"

using namespace std;

class FileHandler {
public:
    void load_templates(Payload* payload);
    void save_templates(Payload* payload);
    void load_roster(Payload* payload, string* roster_name);
    void save_roster(Payload* payload, string* roster_name);

};



#endif //FORC_PA_4_FILEHANDLER_H
