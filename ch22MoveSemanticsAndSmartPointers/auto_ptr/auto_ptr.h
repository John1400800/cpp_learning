// auto_ptr.h
#ifndef AUTO_PTR_H
#define AUTO_PTR_H

template <typename T>
class Auto_ptr {
    T *ptr_;
public:
    Auto_ptr(T* ptr=nullptr);
    ~Auto_ptr();

    Auto_ptr(const Auto_ptr&) = delete;
    Auto_ptr& operator=(const Auto_ptr&) = delete;

    Auto_ptr(Auto_ptr&& a) noexcept;
    Auto_ptr& operator=(Auto_ptr&& a) noexcept;

    T& operator*() const;
};

#endif // AUTO_PTR_H
