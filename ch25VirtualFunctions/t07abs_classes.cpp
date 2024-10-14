#include <cstdlib>
#include <iostream>

class Animal { // This Animal is an abstract base class
protected:
    std::string m_name{};
public:
    Animal(std::string_view name)
        : m_name{ name }
    { }

    const std::string& getName() const {
        return m_name;
    }

    virtual std::string_view speak() const = 0; // that speak() pure virtual func

    virtual ~Animal() = default;
};

std::string_view Animal::speak() const {
    return "???"; // some default implementation
}

class Cow final: public Animal {
public:
    Cow(std::string_view name)
        : Animal{ name }
    { }

    std::string_view speak() const override {
        return "Moo";
    }
};

class DragonFly: public Animal {
public:
    DragonFly(std::string_view name)
        : Animal{ name }
    { }

    std::string_view speak() const override {
        return Animal::speak();
    }
};

int main() {
    Cow cow{ "Betsy" };
    DragonFly dragFly{ "Sally" };
    Animal *animals[]{ &cow, &dragFly };
    for (const Animal *animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    return EXIT_SUCCESS;
}
