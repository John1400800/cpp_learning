#include <cstdlib>
#include <cstdint>
#include <array>
#include <iostream>

template <typename T, std::size_t N>
const T& getThirdElement(std::array<T, N> arr) {
    return std::get<2>(arr);
}

int main() {
    constexpr std::array arr{1, 2, 3};
    std::cout << getThirdElement(arr) << '\n';
    return EXIT_SUCCESS;
}
