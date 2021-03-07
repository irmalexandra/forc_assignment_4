#ifndef FORC_PA_4_SPECIES_H
#define FORC_PA_4_SPECIES_H

#include "Being.h"
#include "iostream"

class Species: public Being {
public:
    Species(bool* unnatural, int* disquiet_min, int* disquiet_max, int* life_min, int* life_max, int* strength_min,
            int* strength_max, int* intelligence_min, int* intelligence_max);

    bool get_unnatural();
    int get_disquiet_range();

    void set_unnatural(bool* unnatural);
    void set_disquiet_range(int* disquiet_min, int* disquiet_max);

    friend std::ostream& operator<< (std::ostream& out, Species* creature);

private:
    bool unnatural;
    int disquiet_min;
    int disquiet_max;
};

#endif //FORC_PA_4_SPECIES_H
