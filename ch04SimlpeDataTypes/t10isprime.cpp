#include /*<c++/13.2/ */ <cstdlib>
#include /*<c++/13.2/ */ <cstdint>
#include /*<c++/13.2/ */ <iostream>

bool isPimple(uint_fast8_t n);

int main() {
    uint_fast64_t n{};
    std::cout << "Enter a number 0 throw 9: ";
    std::cin >> n;
    if (isPimple(static_cast<uint_fast8_t>(n)))
        std::cout << "The digit is prime\n";
    else
        std::cout << "The digit is not prime\n";
    return EXIT_SUCCESS;
}

bool isPimple(uint_fast8_t n) {
    for (uint_fast8_t d = 2; d*d <= n; ++d)
        if (n%d == 0)
            return false;
    return true;
}
