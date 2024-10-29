#include <cstdlib>
#include <cstdint>
#include <string_view>
#include <algorithm>
#include "stat.h"

int main() {
    StaticArray<uint32_t, 3> int3{};
    constexpr uint32_t arr3[]{ 1, 2, 3 };
    std::copy_n(std::begin(arr3), std::size(arr3), int3.getArray());
    print(int3);

    StaticArray<char, 14> char14{};
    constexpr std::string_view hello14{ "Hello, world!" };
    std::copy_n(hello14.begin(), hello14.size(), char14.getArray());
    print(char14);

    StaticArray<char, 12> char12{};
    constexpr std::string_view hello12{ "Hello, mom!" };
    std::copy_n(hello12.begin(), hello12.size(), char12.getArray());
    print(char12);

    return EXIT_SUCCESS;
}
