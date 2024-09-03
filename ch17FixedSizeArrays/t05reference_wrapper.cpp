#include <cstdlib>
#include <cstdint>
#include <array>
#include <functional>
#include <iostream>

int main() {
    uint32_t x{1};
    uint32_t y{2};
    uint32_t z{3};
    std::array<std::reference_wrapper<uint32_t>, 3> arr {x, y, z};
    arr[1].get() = 5;
    std::cout << arr[1] << y << '\n';
    return EXIT_SUCCESS;
}
