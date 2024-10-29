// stor.cpp
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include "stor.h"

template <typename T>
Storage<T>::Storage(const T &value) : value{ value } {}

template <typename T>
template <typename U>
Storage<T>::Storage(const Storage<U> &stor) 
    : value{ static_cast<T>(stor.value) } 
{ }

template <typename T>
void Storage<T>::print(std::ostream &out) {
    out << value << '\n';
}

// Специализация метода печати для double
template <>
void Storage<double>::print(std::ostream &out) {
    out << std::scientific << value << '\n';
}

// Явная инстанциация шаблонов
template class Storage<uint32_t>;
template class Storage<double>;
template class Storage<float>;
template Storage<double>::Storage(const Storage<float> &stor);
