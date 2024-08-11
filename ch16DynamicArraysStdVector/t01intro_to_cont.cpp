#include <cstdint>
#include <cstdlib>
#include <vector>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const std::vector<auto>& vec) {
    os << "[ ";
    for (auto it=vec.begin(); it != vec.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != vec.end())
            std::cout << ", ";
    }
    os << " ]\n";
    return os;
}

int main() {
    std::vector primes{ 2, 4, 6, 8 };
    const std::vector<uint16_t> oddNum{ 1, 3, 5};
    std::vector vovels{'a', 'e', 'i', 'o', 'u'};
    std::cout << "Primes: " << primes << '\n'
        << "Odd numbers: " << vovels << '\n'
        << "Vovel letters: " << vovels << '\n';
    return EXIT_SUCCESS;
}
