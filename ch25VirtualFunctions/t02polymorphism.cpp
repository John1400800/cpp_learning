#include <cstdlib>
#include <string>
#include <string_view>
#include <iostream>

class Animal {
protected:
    std::string m_name{};

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : m_name{ name }
    { }
public:
    const std::string& getName() const { return m_name; }
    virtual std::string_view speak() const { return "???"; }
    virtual ~Animal() = default;
};

class Cat: public Animal {
public:
    Cat(std::string_view name)
        : Animal{ name }
    { }

    virtual std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal {
public:
    Dog(std::string_view name)
        : Animal{ name }
    { }

    virtual std::string_view speak() const { return "Woof"; }
};

int main() {
    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };
    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };

    Animal *animals[] { &fred, &misty, &zeke, &garbo, &pooky, &truffle };
    for (const Animal *animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    return EXIT_SUCCESS;
}
