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
    template<typename T> void write_to_file(T object, std::ostream out){
        out << object;
    };
    void load_data(string file_to_read, InputHandler* input_handler);

    Role* temp_shit();
    Role* temp_shit2();

};



#endif //FORC_PA_4_FILEHANDLER_H
