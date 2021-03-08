#include "Species.h"

Species::Species(speciesStats* species_stats):BaseTemplate(species_stats){
    this->unnatural = species_stats->unnatural;
    this->disquiet_min = species_stats->dis_min;
    this->disquiet_max = species_stats->dis_max;
    this->is_eldritch_horror = species_stats->is_eldritch;
    this->traumatism_min = species_stats->trauma_min;
    this->traumatism_max = species_stats->trauma_max;
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
    if(Species->get_is_eldritch()){
        out << "Eldritch Horror" << std::endl;
    } else{
        out << "Creature" << std::endl;
    }
    out << (BaseTemplate*)(Species);

    if(Species->get_unnatural()){
        out << "Unnatural" << std::endl;
    }else{
        out << "Natural" << std::endl;
    }

    if (Species->is_eldritch_horror){
        out << "Disquiet: 10" << std::endl;
        out << "Traumatism: " << Species->get_traumatism_range() << std::endl;
    }
    else {
        out << "Disquiet: " << Species->get_disquiet_range() << std::endl;
    }

    return out;
};
