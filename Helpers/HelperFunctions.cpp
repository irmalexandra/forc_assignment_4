#include "HelperFunctions.h"
#include <iostream>
#include <cstring>
string clean_string(string* the_string){
    int length = the_string->length();
    char char_array[length + 1];
    string some_string = "";
    int index = 0;
    for (char const c: *the_string ){
        if((c != '\r') || (c != '\n')){
            char_array[index] = c;
            index++;
        }
    }
    for(int i = 0; i < index; i++){
        some_string += char_array[i];
    }
    return some_string;
};


string clean_string2(string* the_string){
    int n = the_string->length();
    string sanetized_string;

    char char_array[n + 1];
    strcpy(char_array, the_string->c_str());

    for (int i = 0; i < n; i++)

        if(char_array[i] != '\n' || char_array[i] != '\r'){
            sanetized_string += char_array[i];
        } else {
            cout << "Found a carriage return, or new line" << endl;
        }

    return sanetized_string;
}

string ultimate_cleaner_3000(string input){
    auto c_input = input.c_str();
    string ret_str = "";
    for(int i = 0; i <= input.length(); i++){
        if ((int)c_input[i] != 13 || (int)c_input[i] != 10){
            ret_str += c_input[i];
        }

    }
  return ret_str;
}

bool ultimate_cleaner_3001(string* input, string* other_string){
    auto c_input = input->c_str();
    auto c_input2 = other_string->c_str();
    for(int i = 0; i <= input->length(); i++){
        if ((int)c_input[i] == 13){
            continue;
        }
        else if((int)c_input[i] != (int) c_input2[i]){
            return false;
        }
    }
    return true;
}

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
    cout << "Splitting string: " << str << endl;
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
        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        if(input == lower){
            return input;
        }
    }
    return input;
}

std::string* gender_picker() {
    int choice;
    enum Gender { Male = 1, Female = 2, Other = 3};
    while(true){
        std::cout << "Pick a gender:\n1. Male\n2. Female\n3. Other"<< std::endl;
        std::cin >> choice;
        if(cin.fail()){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(),'\n');
            continue;
        }
        switch (choice) {
            case Male:
                return new std::string("Male");
            case Female:
                return new std::string("Female");
            case Other:
                return new std::string("Other");
            default:
                std::cout << choice << " is not a valid option";
                break;

        }
    }
}