#include <cstdlib>
#include <cstdint>
#include <iostream>

uint32_t sumNumDig(uint32_t number) {
    if (number < 10)
        return number;
    return sumNumDig(number/10) + number%10;
}
int main() {
    std::cout << sumNumDig(21) << '\n';
    return EXIT_SUCCESS;
}
