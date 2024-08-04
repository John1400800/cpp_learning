#include <cstdint>
#include <cstdlib>
#include <iostream>

class Simpe {
    uint16_t id_{};
public:
    Simpe(uint16_t id) : id_{id} {
        std::cout << "Constructing Simpe" << id_ << '\n';
    }

    ~Simpe() /* here's our destructor */ {
        std::cout << "Destructing Simpe" << id_ << '\n';
    }
    uint16_t getId() const {
        return id_;
    }
};

int main() {
    // Allocate a Simple
    Simpe simple1{ 1 };
    {
        Simpe simple2{ 2 };
    } // simple2 dies here
    return EXIT_SUCCESS;
} // simple1 dies here
