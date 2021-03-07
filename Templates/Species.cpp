#include "Species.h"

Species::Species(bool* unnatural, int* disquiet_min, int* disquiet_max, int* life_min, int* life_max,
                   int* strength_min, int* strength_max, int* intelligence_min, int* intelligence_max):
                   Being(life_min, life_max, strength_min, strength_max, intelligence_min, intelligence_max){
    this->unnatural = *unnatural;
    this->disquiet = *disquiet;
}

bool Species::get_unnatural() {
    return this->unnatural;
}

int Species::get_disquiet_range() {
    return this->disquiet_max - this->disquiet_min;
}

void Species::set_unnatural(bool* unnatural) {
    this->unnatural = *unnatural;
}

void Species::set_disquiet_range(int* disquiet_min, int* disquiet_max) {
    this->disquiet_min = *disquiet_min;
    this->disquiet_max = *disquiet_max;

}

std::ostream& operator<< (std::ostream& out, Species* Species){
    out << (Being*)(Species);
    out << "Unnatural: " << Species->get_unnatural() << std::endl;
    out << "Disquiet: " << Species->get_disquiet() << std::endl;
    return out;
};
