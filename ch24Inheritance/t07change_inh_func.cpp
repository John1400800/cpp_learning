#include <cstdlib>
#include <cstdint>
#include <iostream>

class Base {
private:
    int32_t value_{};
public:
    Base(int32_t value)
        : value_{ value }
    { }
protected:
    void printValue() const {
        std::cout << value_;
    }
};

class Derived : public Base {
public:
    Derived(int32_t value)
        : Base{ value }
    { }

    using Base::printValue;
};

int main() {
    Derived{13}.printValue();
    return EXIT_SUCCESS;
}
