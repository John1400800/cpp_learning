#include <cstdint>      // for uint32_t e.g
#include <cassert>      // for assert
#include <initializer_list> // for self
#include <iostream>     // for cin/cout

#include "structs.hpp"

template <typename T>
void initArray(Array<T>& arr, size_t length) {
    delete[] arr.data;
    arr.data   = length>0? new T[length] : nullptr;
    arr.length = length;
}

template <typename T>
void initArray(Array<T>& arr, const std::initializer_list<T>& inilist) {
    initArray(arr, inilist.size());
    size_t index{0};
    for (const auto& item : inilist)
        arr.data[index++] = item;
}

template <typename T>
void initArray(Array<T>& arr, const Array<T>& src) {
    initArray(arr, src.length);
    for (size_t i{0}; i<arr.length; ++i)
        arr.data[i] = src.data[i];
}

template <typename T>
void moveArray(Array<T>& arr, Array<T>& src) {
    destroyArray(arr);
    arr = src;
    src.data = nullptr;
    destroyArray(src);
}

template <typename T>
void destroyArray(Array<T>& arr) {
    initArray(arr, 0);
}

template <typename T>
void erase(Array<T>& arr) {
    initArray(arr, 0);
}

template <typename T>
void reallocate(Array<T>& arr, size_t length) {
    initArray(arr, length);
}

template <typename T>
void resizeArray(Array<T>& arr, size_t length) {
    if (length == arr.length)
        return;
    if (length == 0) {
        erase(arr);
        return;
    }
    Array<T> tempArr;
    initArray(tempArr, length);
    for (size_t i{0}; i < min(length, arr.length); ++i)
        tempArr.data[i] = arr.data[i];
    moveArray(arr, tempArr);
}

template <typename T>
void insertBeforeIdxInArr(Array<T>& arr, T value, size_t index) {
    assert(index <= arr.length);
    Array<T> tempArr;
    initArray(tempArr, arr.length+1);
    for (size_t i{0}; i<tempArr.length; ++i)
        if (i==index)
            tempArr.data[i] = value;
        else if (i < index)
            tempArr.data[i] = arr.data[i];
        else if (i > index)
            tempArr.data[i] = arr.data[i-1];
    moveArray(arr, tempArr);
}

template <typename T>
void removeIdxArr(Array<T>& arr, size_t index) {
    assert(index < arr.length);
    Array<T> tempArr;
    initArray(tempArr, arr.length-1);
    for (size_t i{0}; i<tempArr.length; ++i)
        if (i<index)
            tempArr.data[i] = arr.data[i];
        else
            tempArr.data[i] = arr.data[i+1];
    moveArray(arr, tempArr);
}

template <typename T>
T& get(Array<T>& arr, size_t index) {
    assert(index < arr.length);
    return arr.data[index];
}

template <typename T>
const T& get(const Array<T>& arr, size_t index) {
    assert(index < arr.length);
    return arr.data[index];
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    if (arr.length == 0)
        return out << "Array is empty!";
    for (size_t i{0}; i<arr.length; ++i)
        out << (i>0?", ":"") << arr.data[i];
    return out;
}

template void initArray<double>(Array<double>& arr, size_t length);
template void initArray<double>(Array<double>& arr, const std::initializer_list<double>& inilist);
template void initArray<double>(Array<double>& arr, const Array<double>& src);
template void moveArray<double>(Array<double>& arr, Array<double>& src);
template void destroyArray<double>(Array<double>& arr);
template void erase<double>(Array<double>& arr);
template void reallocate<double>(Array<double>& arr, size_t length);
template void resizeArray<double>(Array<double>& arr, size_t length);
template void insertBeforeIdxInArr<double>(Array<double>& arr, double value, size_t index);
template void removeIdxArr<double>(Array<double>& arr, size_t index);
template double& get<double>(Array<double>& arr, size_t index);
template const double& get<double>(const Array<double>& arr, size_t index);
template std::ostream& operator<< <double>(std::ostream& out, const Array<double>& arr);

