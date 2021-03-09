#include "FileHandler.h"

Role* FileHandler::temp_shit(){
    auto stats = new speciesStats();
    stats->name = "temphshit1";
    stats->life_min = 3;
    stats->life_max = 4;
    stats->str_max = 5;
    stats->str_min = 1;
    stats->int_min = 1;
    stats->int_max = 6;
    Role* my_role = new Role((baseStats*) stats);
//    auto thinggy = new DataHandler<Role>;
//    thinggy->get_data()->push_back(my_role);
//    thing->DHRoles = thinggy;
    return my_role;
}
Role* FileHandler::temp_shit2(){
    auto stats = new speciesStats();
    stats->name = "tempshit2_thing";
    stats->life_min = 6;
    stats->life_max = 9;
    stats->str_max = 1;
    stats->str_min = 1;
    stats->int_min = 1;
    stats->int_max = 6;
    Role* my_role = new Role((baseStats*) stats);
//    auto thinggy = new DataHandler<Role>;
//    thinggy->get_data()->push_back(my_role);
//    thing->DHRoles = thinggy;
    return my_role;
}


void FileHandler::load_data(string file_to_read, InputHandler* input_handler){
    char single_line[32] = {};
    auto thing = new vector<BaseTemplate>;

    speciesStats* stats;

    string name;
    string type;
    //auto life_range = Range();
    //auto strength_range = Range();
    //auto intelligence_range = Range();

    auto temp_string_array = new std::vector<std::string>;
    //bool natural;
    //auto disquiet_range = Range();
    //auto traumatism_range = Range();
    int amount;

    string line_str;
    ifstream fileIn (file_to_read);
    while (!fileIn.eof()){
        fileIn.getline(single_line, 32);
        line_str = string(single_line);
        amount = stoi(line_str);
        for(int i = 0; i < amount; i++){
            stats = new speciesStats();
            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            name = split_string(line_str)->at(1);
            stats->name = name;

            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            type = line_str;

            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            temp_string_array = split_string(split_string(line_str)->at(1), '-');
            stats->life_min = stoi(temp_string_array->at(0));
            stats->life_max = stoi(temp_string_array->at(1));

            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            temp_string_array = split_string(split_string(line_str)->at(1), '-');
            stats->str_min = stoi(temp_string_array->at(0));
            stats->str_max = stoi(temp_string_array->at(1));

            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            temp_string_array = split_string(split_string(line_str)->at(1), '-');
            stats->int_min = stoi(temp_string_array->at(0));
            stats->int_max = stoi(temp_string_array->at(1));

            if(type != "Person"){
                fileIn.getline(single_line, 32);
                line_str = string(single_line);
                if(line_str == "Natural"){
                    stats->unnatural = false;
                }
                else{
                    stats->unnatural = true;
                }
                fileIn.getline(single_line, 32);
                line_str = string(single_line);
                temp_string_array = split_string(split_string(line_str)->at(1), '-');
                stats->dis_min = stoi(temp_string_array->at(0));
                stats->dis_max = stoi(temp_string_array->at(1));
                if(type == "Eldritch Horror"){
                    fileIn.getline(single_line, 32);
                    line_str = string(single_line);
                    temp_string_array = split_string(split_string(line_str)->at(1), '-');
                    stats->trauma_min = stoi(temp_string_array->at(0));
                    stats->trauma_max = stoi(temp_string_array->at(1));
                    stats->is_eldritch = true;
                }
            }

            if (type == "Person"){
                input_handler->DHRoles->get_data()->push_back(new Role(stats));
            } else if (type == "Eldritch Horror" || type == "Creature") {
                input_handler->DHSpecies->get_data()->push_back(new Species(stats));
            }
            fileIn.getline(single_line, 32); // To skip empty lines
            delete stats;
        }
    }
}