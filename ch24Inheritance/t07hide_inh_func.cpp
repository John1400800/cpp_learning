#include <cstdlib>
#include <cstdint>
#include <iostream>

class Base {
public:
    int32_t m_value{};
};

class Derived : public Base {
private:
    // line below using-declarations change visibility from public to private
    // this can also be done by changing inheritance from public to private
    using Base::m_value;
public:
    Derived(int32_t value) : Base{ value }
    { }
};

int main() {
    std::cout << Base   { 1 }.m_value << '\n'                   // okay: m_value is public in Base
        << Derived{ 2 }.m_value << '\n'                         // error: m_value is private in Derived
        << static_cast<Base>(Derived{ 3 }).m_value << '\n';     // but ;)
    return EXIT_SUCCESS;
}
