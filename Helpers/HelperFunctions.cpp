#include "HelperFunctions.h"

int get_random_integer(int high, int low) {
    return (low + rand() % high);
}