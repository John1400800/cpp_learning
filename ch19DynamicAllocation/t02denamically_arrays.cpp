#include <cstdlib>
#include <cstdint>
#include <iostream>

int main() {
    std::cout << "enter a positive integer: ";
    size_t length{};
    std::cin >> length;
    uint32_t *arrayPtr{ new uint32_t[length]{} };
    std::cout << "Just allocated an array of integers of length " << length << '\n';
    for (size_t i{0}; i<length; ++i)
        arrayPtr[i] = static_cast<uint32_t>(i);
    if (length>5)
        std::cout << arrayPtr[5] << '\n';
    delete[] arrayPtr;
    return EXIT_SUCCESS;
}
