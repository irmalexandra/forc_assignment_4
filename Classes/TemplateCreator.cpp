#include "TemplateCreator.h"

Creature *TemplateCreator::createSpecies() {
    return nullptr;
}

Person *TemplateCreator::createRole() {
    return nullptr;
}

void TemplateCreator::base_stat_setter() {
    int life_min;
    int strength_min;
    int intelligence_min;
    int life_max;
    int strength_max;
    int intelligence_max;

    cout << "Enter lower range for life";
    cin >> life_min;
    cout << "Enter upper range for life";
    cin >> life_max;

    cout << "Enter lower range for strength";
    cin >> strength_min;
    cout << "Enter upper range for strength";
    cin >> strength_max;

    cout << "Enter lower range for intelligence";
    cin >> intelligence_min;
    cout << "Enter upper range for intelligence";
    cin >> intelligence_max;

}
