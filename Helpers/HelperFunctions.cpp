#include "HelperFunctions.h"



//std::vector<std::string>* split_string(std::string string_in, char delim){
//    auto* ret_str = new std::vector<std::string>;
//    if (string_in.length() < 1) return ret_str;
//    std::string temp_string = "";
//    for (auto i : string_in){
//        if (i == delim){
//            ret_str->push_back(temp_string);
//            temp_string = "";
//        }
//        else{
//            temp_string.push_back(i);
//        }
//    }
//    ret_str->push_back(temp_string);
//    return ret_str;
//}

vector<string> split_string(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}


int get_random_integer(const Range& range) {
    if(range.min == range.max){
        return range.min;
    }
    return int(rand() % (range.max - range.min) + range.min);
}

int get_int_within_range(int lower, int upper, const std::string& display_string){
    int input = -1;
    while(input <= lower || input > upper){
        std::cout << "The range is from " << lower << " to " << upper << std::endl;
        std::cout << display_string << std::endl;
        std::cin >> input;
        if(input == lower){
            return input;
        }
    }
    return input;
}

std::string* gender_picker() {
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