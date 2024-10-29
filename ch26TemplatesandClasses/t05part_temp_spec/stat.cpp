#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include "stat.h"

template <typename T, size_t N>
T* StaticArray<T, N>::getArray() {
    return m_array;
}

template <typename T, size_t N>
const T& StaticArray<T, N>::operator[](size_t index) const {
    return m_array[index];
}

template <typename T, size_t N>
T& StaticArray<T, N>::operator[](size_t index) {
    return m_array[index];
}

template <typename T, size_t N>
void print(const StaticArray<T, N>& array) {
    for (size_t i{ 0 }; i < N; ++i)
        std::cout << (i>0?", ":"") << array[i];
    std::cout << '\n';
}

template <size_t N>
void print(const StaticArray<char, N>& array) {
    for (size_t i{ 0 }; i < N; ++i)
        std::cout << array[i];
    std::cout << '\n';
}

template class StaticArray<uint32_t,   3>;
template class StaticArray<char,      14>;
template class StaticArray<char,      12>;

template void print(const StaticArray<uint32_t,3>& array);
template void print(const StaticArray<char,   14>& array);
template void print(const StaticArray<char,   12>& array);
