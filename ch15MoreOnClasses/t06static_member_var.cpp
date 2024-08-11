#include <cstdint>
#include <cstdlib>
#include <iostream>

class Something {
public:
    static uint16_t value;
};
uint16_t foo;

uint16_t Something::value{ 2u }; // defines the static member variable

int main() {
    ++Something::value;
    std::cout << Something::value << '\n'
        << (Something{}).value << ' ' << foo << '\n';
    return EXIT_SUCCESS;
}
