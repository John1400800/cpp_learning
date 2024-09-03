#include <cstdlib>
#include <array>
#include <iostream>

template <typename T, std::size_t N>
constexpr void printArray(const std::array<T, N>& arr) {
    if constexpr (N > 0) {
        std::cout << "the array ( ";
        bool first{ true };
        for (const T& item : arr) {
            std::cout << (first? "": ", ") << item;
            first = false;
        }
        std::cout << " ) has length " << std::size(arr) << '\n';
    } else
        std::cout << "the array is empty\n";
}

int main() {
    constexpr std::array arr{1, 2, 3, 4};
    printArray(arr);
    std::array<bool, 0> arr2;
    printArray(arr2);
    return EXIT_SUCCESS;
}
