#include <cstdlib>
#include <cstdint>
#include <iostream>

class Base {
private:
    int32_t m_value{};
public:
    Base(int32_t value) : m_value{ value } { }

    int32_t getValue() const { return m_value; }
};

class Derived : public Base {
public:
    Derived(int32_t value) : Base{ value } { }
    int32_t getValue() const = delete;
};

int main() {
    std::cout << Derived{ 1 }.getValue() << '\n'
        << Derived{ 2 }.Base::getValue() << '\n' // two ways:
        << static_cast<Base>(Derived{ 3 }).getValue() << '\n';
    return EXIT_SUCCESS;
}
