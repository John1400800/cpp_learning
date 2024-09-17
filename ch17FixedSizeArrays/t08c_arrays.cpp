#include <cstdlib>
#include <cstdint>
#include <iomanip>
#include <iostream>

constexpr size_t ndigits(uint32_t number) {
    size_t count{1};
    while ((number /= 10) > 0)
        ++count;
    return count;
}

inline namespace Settings {
    constexpr uint32_t maxNum   { 1'000 };
    constexpr uint32_t rows     {     9 };
    constexpr size_t   indent   { ndigits(maxNum)-1 };
}

constexpr bool isPrime(uint32_t number) {
    if (number < 2)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (uint32_t b{3}; b*b <= number; b+=2)
        if (number % b == 0)
            return false;
    return true;
}

int main() {
    uint32_t primes[maxNum+1]{};
    for (uint32_t number{0}, count{0}; number<=maxNum; ++number)
        if (isPrime(number))
            primes[count++] = number;
    uint32_t count{0};
    for (auto prime : primes) { // primes not decayed C-style array
        if (prime == 0) {
            std::cout << '\n';
            break;
        }
        if (count%rows!=0)
            std::cout << ", ";
        else if (count > 0)
            std::cout << "\n";
        std::cout << std::setw(indent) << prime;
        ++count;
    }
    return EXIT_SUCCESS;
}
