// elem.h

#ifndef ELEM_H
#define ELEM_H

#include <iostream>
#include <cstdint>

template <typename T>
class Elem {
public:
    T* data_;
    static size_t currId;
    size_t id_;

    Elem();
    Elem(T data);
    ~Elem();
    Elem(const Elem& el);
    Elem& operator=(const Elem& el);

    // Объявляем оператор < для использования в selSort
    friend bool operator<(const Elem<T>& a, const Elem<T>& b) {
        return *a.data_ < *b.data_;
    }

    // Объявляем оператор << для использования в std::cout
    friend std::ostream& operator<<(std::ostream& out, const Elem<T>& el) {
        return out << *el.data_;
    }
};

#endif // ELEM_H
