#include <cstdlib>
#include <cstdint>
#include <iostream>

class Base {
public:
    virtual ~Base() {
        std::cout << "Calling ~Base()\n";
    }
};

class Derived final: public Base {
private:
    uint32_t *m_array{};
public:
    Derived(size_t length)
        : m_array{ new uint32_t[length] }
    { }

    Derived(const Derived&) = delete;
    Derived& operator=(const Derived&) = delete;

    virtual ~Derived() {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main() {
    Base *derived{new Derived{5} };
    delete derived;
    return EXIT_SUCCESS;
}
