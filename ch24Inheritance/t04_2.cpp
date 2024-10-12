#include <cstdlib>
#include <cstdint>
#include <string_view>
#include <iostream>

class A {
public:
    A(uint32_t a) {
        std::cout << "A: " << a << '\n';
    }
};

class B : public A {
public:
    B(uint32_t a, double b)
    : A( a )
    {
        std::cout << "B: " << b << '\n';
    }
};

class C : public B {
public:
    C(uint32_t a, double b, std::string_view c)
    : B( a, b )
    {
        std::cout << "C: " << c << '\n';
    }
};

int main() {
    C c{2, 3.5, "Hello world"};
    return EXIT_SUCCESS;
}
