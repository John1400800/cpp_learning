#include "auto_ptr.h"
#include "elem.h"

template <typename T>
Auto_ptr<T>::Auto_ptr(T* ptr)
    : ptr_{ptr}
{ }

template <typename T>
Auto_ptr<T>::~Auto_ptr() {
    delete ptr_;
}

template <typename T>
Auto_ptr<T>::Auto_ptr(Auto_ptr&& a) noexcept
    : ptr_{ a.ptr_ }
{
    a.ptr_ = nullptr;
}

template <typename T>
Auto_ptr<T>& Auto_ptr<T>::operator=(Auto_ptr&& a) noexcept {
    if (this == &a)
        return *this;
    delete ptr_;
    ptr_ = a.ptr_;
    a.ptr_ = nullptr;
    return *this;
}

template <typename T>
T& Auto_ptr<T>::operator*() const {
    return *ptr_;
}

template class Auto_ptr<Elem<uint32_t>>; 
