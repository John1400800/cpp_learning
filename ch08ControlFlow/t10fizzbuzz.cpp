#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string_view>

namespace {
    constexpr uint8_t LOWER{   1 };
    constexpr uint8_t UPPER{ 106 };
}

int main() {
    for (uint8_t number{ LOWER }; number<=UPPER; ++number) {
        using namespace std::literals;
        if (number%3==0)
            std::cout << "fizz"sv;
        if (number%5==0)
            std::cout << "buzz"sv;
        if (number%7==0)
            std::cout << "pop"sv;
        else if (number%3!=0 && number%5!=0)
            std::cout << static_cast<uint16_t>(number);
        std::cout << '\n';
    }
    return EXIT_SUCCESS;
}
