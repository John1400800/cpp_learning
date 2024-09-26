#include <cstdlib>
#include <cstdint>
#include <iostream>

int main() {
    uint32_t *ptr{ new (std::nothrow) uint32_t{} };
    if (!ptr)
        std::cout << "Could not allocate memory\n";
    else
        std::cout << "Memory successefully allocate\n";
    delete ptr; // Deleting a null pointer is okay, and does nothing
    return EXIT_SUCCESS;
}
