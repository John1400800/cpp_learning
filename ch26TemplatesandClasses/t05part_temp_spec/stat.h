#ifndef STATICARRAY_H
#define STATICARRAY_H

#include <cstdlib>
#include <iostream>
#include <string_view>

template <typename T, size_t size>
class StaticArray
{
private:
    T m_array[size]{};

public:
    T* getArray();
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
};

template <typename T, size_t size>
void print(const StaticArray<T, size>& array);

template <size_t size>
void print(const StaticArray<char, size>& array);

#endif
