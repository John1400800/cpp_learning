#include <cstdlib>
#include <cstdint>
#include <iostream>

class Base {
public:
    void print(int32_t) { std::cout << "Base::print(int32_t)\n"; }

    void print(double)  { std::cout << "Base::print(int32_t)\n"; }
};

class Derived: public Base {
public:
#ifdef BAD_CODE
    void print(int32_t n) { Base::print(n); }                      
#else
    using Base::print;
    void print(double)  { std::cout << "Derived::print(double)\n"; }
#endif
};

int main() {
    Derived{}.print(12);
    return EXIT_SUCCESS;
}
