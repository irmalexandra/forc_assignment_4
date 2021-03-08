#include "FileHandler.h"

void make_templates_list(string file_to_read, InputHandler input_handler){
    char single_line[32] = {};
    bool reading_role_line = false;
    bool reading_species_line = false;
    bool reset_single_template = true;
    auto thing = new vector<BaseTemplate>;

    auto stats = new speciesStats();

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

            fileIn.getline(single_line, 32);
            line_str = string(single_line);
            name = split_string(line_str)->at(1);

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
                }
            }

            if (type == "Person"){
                input_handler.DHRoles->get_data()->push_back(new Role((baseStats*) stats));
            } else if (type == "Eldritch Horror") {
                input_handler.DHSpecies->get_data()->push_back(new Species(stats));
            }

        }
    }
}