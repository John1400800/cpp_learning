#include <cstdint>
#include <cstdlib>
#include <random>
#include <iostream>

int main() {
    std::random_device rd{};
    std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt{ ss };
    std::uniform_int_distribution die6{1, 6};
    for (uint8_t count{ 0 }; count<40; ++count)
        std::cout << die6(mt)
            << (count%10==9?'\n':' ');
    return EXIT_SUCCESS;
}
