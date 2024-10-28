#include <cstdlib>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include "array.h"

template <typename T>
Array<T>::Array(size_t length)
    : length_{ length }
    , data_{ new T[length_]{} }
{ }

template <typename T>
Array<T>::Array(std::initializer_list<T> iniList)
    : Array(iniList.size())
{
    size_t i{0};
    for (auto& item : iniList) {
        data_[i++] = item;
    }
}

template <typename T>
Array<T>::Array(Array&& arr) noexcept
    : length_{arr.length_}, data_{arr.data_}
{
    arr.data_ = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& arr) noexcept {
    if (this != &arr)
        return *this;
    length_ = arr.length_;
    data_ = arr.data_;
    arr.data_ = nullptr;
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data_;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    return data_[index];
}

template <typename T>
size_t Array<T>::size() const {
    return length_;
}

template <typename T>
const T *Array<T>::begin() const {
    return data_;
}

template <typename T>
const T *Array<T>::end() const {
    return data_ + length_;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    bool isFirst{ true };
    for (const T& item : arr) {
        out << (!isFirst? ", " : "") << item;
        isFirst = false;
    }
    return out;
}

template class Array<uint32_t>;
template class Array<int32_t >;
template class Array<double  >;
template std::ostream& operator<<(std::ostream&, const Array<uint32_t>&);
template std::ostream& operator<<(std::ostream&, const Array<int32_t >&);
template std::ostream& operator<<(std::ostream&, const Array<double  >&);

