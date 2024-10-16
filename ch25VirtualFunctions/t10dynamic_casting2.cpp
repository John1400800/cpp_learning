#include <cstdlib>
#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

enum class ClassId {
    base,
    derived
};

class Base {
protected:
    uint32_t value_{};
public:
    Base(uint32_t value)
        : value_{ value }
    { }

    virtual ClassId getClassId() const { return ClassId::base; };
    virtual ~Base() = default;
};

class Derived: public Base {
private:
    std::string name_{};
public:
    Derived(uint32_t value, std::string_view name)
        : Base{ value }, name_{ name }
    { }

    const std::string& getName() const { return name_; }

    ClassId getClassId() const override { return ClassId::derived; }
};

Base *getObject(bool bReturnDerived) {
    if (bReturnDerived)
        return new Derived{ 1, "Apple" };
    return new Base{ 2 };
}

int main() {
    Base *b{getObject( true )};
    if (b->getClassId() == ClassId::derived)
        std::cout << "The name of the Derived is: "
            << static_cast<Derived*>(b)->getName() << '\n';
    delete b;
    return EXIT_SUCCESS;
}
