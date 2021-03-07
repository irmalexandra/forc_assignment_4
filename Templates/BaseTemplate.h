//
// Created by emmik on 05/03/2021.
//

#ifndef FORC_PA_4_BaseTemplate_H
#define FORC_PA_4_BaseTemplate_H

#include "iostream"


class BaseTemplate {
public:
    BaseTemplate(int* life_min, int* life_max, int* strength_min, int* strength_max, int* intelligence_min, int* intelligence_max);
    ~BaseTemplate();

    int get_life_range();
    int get_strength_range();
    int get_intelligence_range();

    void set_life_range(int* life_min, int* life_max);
    void set_strength_range(int* strength_min, int* strength_max);
    void set_intelligence_range(int* intelligence_min, int* intelligence_max);

    friend std::ostream& operator<< (std::ostream& out, BaseTemplate* BaseTemplate);
private:
    int life_min;
    int strength_min;
    int intelligence_min;
    int life_max;
    int strength_max;
    int intelligence_max;
};


#endif //FORC_PA_4_BaseTemplate_H
