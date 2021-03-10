#include <algorithm>
#include "FileHandler.h"



void FileHandler::load_templates(Payload* payload){
    char single_line[32] = {};
    auto thing = new vector<BaseTemplate>;
    string filename = "../Resources/template_file.txt";
    speciesStats* stats;

    string name;
    string type;


    auto temp_string_array = new std::vector<std::string>;
    int amount;

    string line_str;
    ifstream fileIn (filename);
    while (!fileIn.eof()){
        fileIn.getline(single_line, 32);
        line_str = string(single_line);

        if(line_str.empty()){
            continue;
        }
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
            stats->type = type;


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
                payload->DHRoles->get_data()->push_back(new Role(stats));
            } else if (type == "Eldritch Horror" || type == "Creature") {
                payload->DHSpecies->get_data()->push_back(new Species(stats));
            }
            fileIn.getline(single_line, 32); // To skip empty lines
            delete stats;
        }
    }
}

void FileHandler::save_templates(Payload* payload) {
    string filename = "../Resources/template_file.txt";
    ofstream fileout(filename, ios::trunc);

    fileout << payload->DHSpecies->get_data()->size() << endl;
    fileout << payload->DHSpecies;
    fileout << payload->DHRoles->get_data()->size() << endl;
    fileout << payload->DHRoles;
    fileout.close();
}

void FileHandler::save_roster(Payload* payload, string* roster_name){
    ofstream fileout(*roster_name, ios::trunc);

    fileout << payload->DHInvestigators->get_data()->size() << endl;
    fileout << payload->DHInvestigators;
    fileout << payload->DHPersons->get_data()->size() << endl;
    fileout << payload->DHPersons;
    fileout << payload->DHCreatures->get_data()->size() << endl;
    fileout << payload->DHCreatures;
    fileout << payload->DHEldritch_Horrors->get_data()->size() << endl;
    fileout << payload->DHEldritch_Horrors;
    fileout.close();
}

void FileHandler::load_roster(Payload *payload, string *roster_name) {
    char single_line[32] = {};
    cout << *roster_name << endl;
    ifstream fileIn (*roster_name);
    auto stats = new baseIndividualStats();

    string line_string;
    string type;
    string template_name;


    int amount;
    while (!fileIn.eof()){
        fileIn.getline(single_line, 32);
        line_string = string(single_line);

        if(line_string.empty()){
            continue;
        }
        amount = stoi(line_string);
        for(int i = 0; i < amount; i++){
            fileIn.getline(single_line, 32);
            line_string = string(single_line);
            stats->name = split_string(line_string)->at(1);

            fileIn.getline(single_line, 32);
            line_string = string(single_line);
            type = line_string;

            fileIn.getline(single_line, 32);
            line_string = string(single_line);
            template_name = line_string;

            fileIn.getline(single_line, 32);
            line_string = string(single_line);
            stats->life = stoi(split_string(line_string)->at(1));

            fileIn.getline(single_line, 32);
            line_string = string(single_line);
            stats->strength = stoi(split_string(line_string)->at(1));

            fileIn.getline(single_line, 32);
            line_string = string(single_line);
            stats->intelligence = stoi(split_string(line_string)->at(1));

            fileIn.getline(single_line, 32);
            line_string = string(single_line);
            if(type == "Creature" || type == "Eldritch Horror"){
                auto it = find_if(payload->DHSpecies->get_data()->begin(), payload->DHSpecies->get_data()->end(),
                                  [&template_name]( Species* obj) {return obj->get_name() == template_name;});
                auto index = std::distance(payload->DHSpecies->get_data()->begin(), it);
                auto species = payload->DHSpecies->get_data()->at(index);

                // IMPLEMENT TEMPLATE LOOKUP
                stats->unnatural = (line_string != "Natural");
                fileIn.getline(single_line, 32);
                line_string = string(single_line);
                stats->disquiet = stoi(split_string(line_string)->at(1));



                if (type == "Eldritch Horror"){
                    fileIn.getline(single_line, 32);
                    line_string = string(single_line);
                    stats->traumatism = stoi(split_string(line_string)->at(1));
                    payload->DHEldritch_Horrors->get_data()->push_back(new EldritchHorror(stats, species));

                }
                else{
                    payload->DHCreatures->get_data()->push_back(new Creature(stats, species));
                }

            }
            else{
                stats->gender = split_string(line_string)->at(1);
                fileIn.getline(single_line, 32);
                line_string = string(single_line);
                stats->fear = stoi(split_string(line_string)->at(1));

                auto it = find_if(payload->DHRoles->get_data()->begin(), payload->DHRoles->get_data()->end(),
                                  [&template_name]( Role* obj) {return obj->get_name() == template_name;});
                auto index = std::distance(payload->DHRoles->get_data()->begin(), it);
                auto role = payload->DHRoles->get_data()->at(index);
                if(type == "Person"){
                    payload->DHPersons->get_data()->push_back(new Person(stats, role));
                }
                if(type == "Investigator"){
                    fileIn.getline(single_line, 32);
                    line_string = string(single_line);
                    stats->terror = stoi(split_string(line_string)->at(1));
                    payload->DHPersons->get_data()->push_back(new Investigator(stats, role));
                }
            }
        }
    }

}
