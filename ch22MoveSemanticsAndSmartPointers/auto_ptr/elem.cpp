// elem.cpp
#include "elem.h"

template <typename T>
size_t Elem<T>::currId{ 0 };

template <typename T>
Elem<T>::Elem()
    : data_{ nullptr }, id_{ currId++ }
{
}

template <typename T>
Elem<T>::Elem(T data)
    : data_{ new T{data} }, id_{ currId++ }
{
    std::cout << "Elem: " << id_ << " acquired\n";
}

template <typename T>
Elem<T>::~Elem() {
    delete data_;
    std::cout << "Elem: " << id_ << " destroyed\n";
}

template <typename T>
Elem<T>::Elem(const Elem& el)
    : data_{ el.data_ ? new T{ *el.data_ } : nullptr }, id_{ currId++ }
{
    std::cout << "Elem: " << id_ << " copy"
        " from elem: " << el.id_ << "\n";
}

template <typename T>
Elem<T>& Elem<T>::operator=(const Elem& el) {
    if (this == &el)
        return *this;
    delete data_;
    data_ = el.data_ ? new T{ *el.data_ } : nullptr;
    return *this;
}

template class Elem<uint32_t>;  // Экспортируем класс для uint32_t
