#include <cstdlib>
#include <cstdint>
#include <iostream>

constexpr uint32_t fibonacci(size_t count) {
    uint32_t fib1{1}, fib2{1};
    while (count-- > 2) {
        fib2 += fib1;
        fib1 = fib2 - fib1;
    }
    return fib2;
}

int main() {
    constexpr uint32_t fib8{fibonacci(8)};
    std::cout << fib8 << '\n';
    return EXIT_SUCCESS;
}
