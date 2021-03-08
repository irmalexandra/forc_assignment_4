#include "Role.h"

Role::Role(baseStats* base_stats):BaseTemplate(base_stats){
}

std::ostream& operator<< (std::ostream& out, Role* Role) {
    out << (BaseTemplate*)(Role);
    return out;
}

