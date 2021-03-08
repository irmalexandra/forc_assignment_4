#ifndef FORC_PA_4_BaseTemplate_H
#define FORC_PA_4_BaseTemplate_H

#include "iostream"

struct baseStats {
    std::string name = "";
    int life_min = 0;
    int life_max = 0;
    int str_min = 0;
    int str_max = 0;
    int int_min = 0;
    int int_max = 0;
};

struct Range {
    Range(){

    }

    Range(int min, int max){
        this->min = min;
        this->max = max;
    };

    friend std::ostream& operator<< (std::ostream& out, Range range){
        out << range.min << "-" << range.max;
        return out;
    };

    int min = 0;
    int max = 0;
};

class BaseTemplate {
public:
    BaseTemplate(baseStats* baseStats);
//    ~BaseTemplate();

    std::string get_name();

    Range get_life_range();
    Range get_strength_range();
    Range get_intelligence_range();

    void set_life_range(int* life_min, int* life_max);
    void set_strength_range(int* strength_min, int* strength_max);
    void set_intelligence_range(int* intelligence_min, int* intelligence_max);
    void set_name(std::string name);

    friend std::ostream& operator<< (std::ostream& out, BaseTemplate* BaseTemplate);
private:
    std::string name;
    int life_min;
    int strength_min;
    int intelligence_min;
    int life_max;
    int strength_max;
    int intelligence_max;
};


#endif //FORC_PA_4_BaseTemplate_H
