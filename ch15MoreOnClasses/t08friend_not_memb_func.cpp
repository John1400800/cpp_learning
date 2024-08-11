#include <cstdint>
#include <cstdlib>
#include <iostream>

class Accumulator {
    uint32_t value_{ 0 };
public:
    const Accumulator& add(uint32_t value=1u);
    friend const Accumulator& print(const Accumulator& accumulator);
};


const Accumulator& Accumulator::add(uint32_t value) {
    value_ += value;
    return *this;
}

const Accumulator& print(const Accumulator& accumulator) {
    std::cout << accumulator.value_ << '\n';
    return accumulator;
}

int main() {
    Accumulator acc{};
    print(acc.add());
    return EXIT_SUCCESS;
}
