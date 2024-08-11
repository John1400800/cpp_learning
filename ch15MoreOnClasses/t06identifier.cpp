#include <cstdint>
#include <cstdlib>
#include <iostream>

class Something {               // Therefore a static member function that is defined
    static uint32_t idGen;      // in a header file should be made inline so as not
    uint32_t id_;               // to violate the One Definition Rule (ODR) if that
public:                         // header is then included into multiple translation
    Something();                // units.
    uint32_t getId() const;
};

uint32_t Something::idGen{ 0 };
Something::Something() :id_{ Something::idGen++ } {}

uint32_t Something::getId() const {
    return id_;
}

int main() {
    Something first{};
    Something second{};
    Something third{};
    std::cout
        << "first object id is: " << first.getId() << '\n'
        << "second object id is: " << second.getId() << '\n'
        << "third object id is: " << third.getId() << '\n';
    return EXIT_SUCCESS;
}
