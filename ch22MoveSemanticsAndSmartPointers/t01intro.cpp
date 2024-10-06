#include <cstdlib>
#include <iostream>


/* The core problem with the design of std::auto_ptr is that
 * prior to C++11, the C++ language simply had no mechanism to
 * differentiate “copy semantics” from “move semantics”.
 * Overriding the copy semantics to implement move semantics
 * leads to weird edge cases and inadvertent bugs. For example,
 * you can write res1 = res2 and have no idea whether res2 will
 * be changed or not
 *
 * Because of this, in C++11, the concept of “move” was formally
 * defined, and “move semantics” were added to the language to
 * properly differentiate copying from moving. Now that we’ve set
 * the stage for why move semantics can be useful, we’ll explore
 * the topic of move semantics throughout the rest of this
 * chapter. We’ll also fix our Auto_ptr class using move
 * semantics. */
template <typename T>
class Auto_ptr {
    T *ptr_;

    void move(Auto_ptr& a) {
        ptr_ = a.ptr_;
        a.ptr_ = nullptr;
    }

public:
    Auto_ptr(T *ptr=nullptr)
        :ptr_{ptr}
    { }

    ~Auto_ptr() {
        delete ptr_;
    }

    Auto_ptr(Auto_ptr& a) {
        move(a);
    }

    Auto_ptr& operator=(Auto_ptr& a) {
        if (this == &a)
            return *this;
        delete ptr_;
        move(a);
        return *this;
    }

    T& operator* () const { return *this; };
    T* operator->() const { return  this; };
    bool  isNull() const { return ptr_ == nullptr; }
};

struct Resource {
    Resource() {
        std::cout << "Resource acquired\n";
    }
    ~Resource() {
        std::cout << "Resource desroyed\n";
    }
};

int main() {
    Auto_ptr<Resource> res1{new Resource{}};
    Auto_ptr<Resource> res2;
    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
    res2 = res1;
    std::cout << "Ownership transferred\n";
    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
    return EXIT_SUCCESS;
}
