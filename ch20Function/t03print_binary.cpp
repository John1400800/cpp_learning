#include <cstdlib>
#include <cstdint>
#include <iostream>

void printBinary(uint32_t number) {
    if (number > 1)
        printBinary(number / 2);
    std::cout << number % 2;
}

int main() {
    printBinary(-15);
    std::cout << '\n';
    return EXIT_SUCCESS;
}
