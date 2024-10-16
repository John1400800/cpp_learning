#include <cstdlib>
#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

class Base {
protected:
    uint32_t value_{};
public:
    Base(uint32_t value)
        : value_{ value }
    { }

    // virtual ~Base() = default;
};

class Derived: public Base {
    std::string name_{};
public:
    Derived(uint32_t value, std::string_view name)
        : Base{ value }, name_{ name }
    { }

    const std::string& getName() const {
        return name_;
    }
};

int main() {
    Base *BasePtrToDerived{ new Derived{5, "name" } };
    Derived *DerivedPtrToDerived{ dynamic_cast<Derived*>(BasePtrToDerived) }; // in this context also  may use static_cast
    if (DerivedPtrToDerived) // != nullptr
        std::cout << dynamic_cast<Derived*>(ptrToDerived)->getName() << '\n';
    else
        std::cout << "dynamic_cast error\n";
    return EXIT_SUCCESS;
}
