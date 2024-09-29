#include <cstdlib>
#include <array>
#include <algorithm>
#include <iostream>

template <typename T, size_t N>
bool allIsEven(std::array<T, N>& arr) {
    auto isEven{
        [](T num) {
            return num % 2 == 0;
        }
    };
    return std::all_of(arr.begin(), arr.end(), isEven);
}

int main() {
    std::array arr{0, 2, 6, 4};
    std::cout << std::boolalpha << allIsEven(arr) << '\n';
    return EXIT_SUCCESS;
}
