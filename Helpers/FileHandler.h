#ifndef FORC_PA_4_FILEHANDLER_H
#define FORC_PA_4_FILEHANDLER_H
#include <random>
#include "iostream"



class FileHandler {
public:
    template<typename T> void write_to_file(T object, std::ostream out){
        out << object;
    };
    static void read_from_file();
};



#endif //FORC_PA_4_FILEHANDLER_H
