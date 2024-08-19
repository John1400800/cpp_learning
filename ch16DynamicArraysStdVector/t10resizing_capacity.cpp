#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>

constexpr void printCapLen(std::vector<auto>& vec) {
    std::cout << "capacity: " << vec.capacity() << ", size: " << vec.size() << '\n';
}

int main() {
    std::vector<uint32_t> vec(1000);
    printCapLen(vec);
    vec.resize(0);
    printCapLen(vec);
    vec.shrink_to_fit();
    printCapLen(vec);
    return EXIT_SUCCESS;
}
