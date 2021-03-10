#include "HelperFunctions.h"



std::vector<std::string>* split_string(std::string string_in, char delim){
    auto* ret_str = new std::vector<std::string>;
    std::string temp_string = "";
    for (auto i : string_in){
        if (i == delim){
            ret_str->push_back(temp_string);
            temp_string = "";
        }
        else{
            temp_string.push_back(i);
        }
    }
    ret_str->push_back(temp_string);
    return ret_str;
}
