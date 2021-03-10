#include <chrono>

#include "Models/Investigator.h"
#include "Models/EldritchHorror.h"
#include "Models/Creature.h"
#include "Models/Person.h"
#include "Classes/IndividualCreator.h"
#include "string"
#include "Helpers/InputHandler.h"
#include "Helpers/FileHandler.h"


//#include "Helpers/HelperFunctions.h"

void stuff(InputHandler* thing){
    thing->DHRoles->get_data();
    thing->DHSpecies->get_data();

}

using namespace std;
int main() {
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    auto input_handler = new InputHandler();
//    file_handler->load_templates("../Resources/template_file.txt");


    input_handler->main_menu();


    //file_handler->save_templates(input_handler);
    return 0;

}
