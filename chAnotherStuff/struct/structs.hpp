#ifndef ARRAY_H
#define ARRAY_H

#include <cstdint>      // for uint32_t e.g
#include <cassert>      // for assert
#include <initializer_list> // for self
#include <iostream>     // for cin/cout

template <typename T>
struct Array {
    T           *data{nullptr};
    size_t      length{0};
};

template <typename T>
constexpr T min(const T& a, const T& b) {
    return a < b ? a : b;
}

template <typename T>
void initArray(Array<T>& arr, size_t length=0);

template <typename T>
void initArray(Array<T>& arr, const std::initializer_list<T>& inilist);

template <typename T>
void initArray(Array<T>& arr, const Array<T>& src);

template <typename T>
void moveArray(Array<T>& arr, Array<T>& src);

template <typename T>
void destroyArray(Array<T>& arr);

template <typename T>
void erase(Array<T>& arr);

template <typename T>
void reallocate(Array<T>& arr, size_t length);

template <typename T>
void resizeArray(Array<T>& arr, size_t length);

template <typename T>
void insertBeforeIdxInArr(Array<T>& arr, T value, size_t index);

template <typename T>
void removeIdxArr(Array<T>& arr, size_t index);

template <typename T>
T& get(Array<T>& arr, size_t index);

template <typename T>
const T& get(const Array<T>& arr, size_t index);

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr);

#endif // ARRAY_H
