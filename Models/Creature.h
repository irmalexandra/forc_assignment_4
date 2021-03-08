#ifndef FORC_PA_4_CREATURE_H
#define FORC_PA_4_SPECIES_H

#include "Being.h"
#include "iostream"

class Creature: public Being {
public:
    Creature(bool* unnatural, int* disquiet, int* life, int* strength, int* intelligence);

    bool get_unnatural();
    int get_disquiet();

    void set_unnatural(bool* unnatural);
    void set_disquiet(int* disquiet);

    friend std::ostream& operator<< (std::ostream& out, Creature* creature);

private:
    bool unnatural;
    int disquiet;
};


#endif //FORC_PA_4_CREATURE_H
