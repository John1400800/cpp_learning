#ifndef ARRAY_H
#define ARRAY_H
#include <cstdlib>
#include <cstdint>
#include <initializer_list>
#include <iostream>

template <typename T>
class Array {
    size_t length_{};
    T *data_{};
public:
    Array(size_t length);
    Array(std::initializer_list<T> iniList);

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    Array(Array&& arr) noexcept;
    Array& operator=(Array&& arr) noexcept;

    ~Array();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
    const T *begin() const;
    const T *end() const;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr);

#endif // ARRAY_H
