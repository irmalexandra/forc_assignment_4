#include "DataHandler.h"

template<typename T>
DataHandler<T>::DataHandler() {
    this->data = new std::vector<T>;
}

template<typename T>
DataHandler<T>::~DataHandler<T>() {
    this->data->erase(this->data->begin(), this->data->end());
    delete this->data;
    this->data = nullptr;
}

template<typename T>
std::vector<T*>* DataHandler<T>::get_data() {
    return this->data;
}

template<typename T>
void DataHandler<T>::display_data() {
    for (auto item : this->data){
        std::cout << item << std::endl;
    }
}
