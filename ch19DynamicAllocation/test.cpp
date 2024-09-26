#include <cstdlib>
#include <cstdint>
#include <iostream>

int main() {
    for (uint32_t *ptr{nullptr}, count{0}; count!=10; ++count) {
        std::cout << (count>0?", ":"") << *(ptr = new uint32_t{count});
        ; // do thimething with ptr
        delete ptr; // deallocate memory on ptr
    }
    std::cout << '\n';
    return EXIT_SUCCESS;
}
