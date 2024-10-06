#include <cstdlib>
#include <iostream>

template <typename T>
class Auto_ptr {
    T *ptr_;
public:
    Auto_ptr(T *ptr=nullptr)
        : ptr_{ ptr }
    { }
    ~Auto_ptr() {
        delete ptr_;
    }
    Auto_ptr(const Auto_ptr& a) = delete;

    Auto_ptr(Auto_ptr&& a) noexcept
        : ptr_{ a.ptr_ }
    {
        a.ptr_ = nullptr;
    }

    Auto_ptr& operator=(const Auto_ptr& a) = delete;

    Auto_ptr& operator=(Auto_ptr&& a) noexcept {
        if (this == &a)
            return *this;
        delete ptr_;
        ptr_   = a.ptr_;
        a.ptr_ = nullptr;
        return *this;
    }
};

struct Resource {
    Resource() {
        std::cout << "Resource acquired\n";
    }
    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
};

Auto_ptr<Resource> generateResource() {
    Auto_ptr<Resource> res{ new Resource };
    return res;
}

int main() {
    Auto_ptr<Resource> res1;
    res1 = generateResource();
    return EXIT_SUCCESS;
}
