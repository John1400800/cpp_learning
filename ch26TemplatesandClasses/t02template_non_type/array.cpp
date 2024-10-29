// array.cpp
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include "array.h"

template <typename T, size_t N>
T& StaticArray<T, N>::operator[](size_t index) {
    return array_[index];
}

template <typename T, size_t N>
const T& StaticArray<T, N>::operator[](size_t index) const {
    return array_[index];
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, StaticArray<T, N> arr) {
    for (size_t i{0}; i<N; ++i)
        std::cout << (i>0?", ":"") << arr[i];
    return out;
}

template class StaticArray<uint32_t, 3>;
template std::ostream& operator<<(std::ostream& out, StaticArray<uint32_t, 3> arr);
