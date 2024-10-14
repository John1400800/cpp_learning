#include <cstdlib>
#include <string_view>
#include <iostream>

class Base {
public:
    virtual std::string_view getName() const {
        return "Base";
    }

    virtual ~Base() = default;
};

class Derived: public Base {
public:
    virtual std::string_view getName() const {
        return "Derived";
    }
};

int main() {
    Derived derived{};
    Base& rBaseToDerived{ derived };
    std::cout << "rBaseToDerived is a " << rBaseToDerived.getName() << '\n';
    return EXIT_SUCCESS;
}
