#include <cstdint>
#include <cstdlib>
#include <vector>
#include <iostream>

int main() {
    std::vector<uint16_t> prime{ 2, 3, 5, 7, 11 };
    for (auto index=std::ssize(prime)-1;index>=0; --index) {
        if (index==std::ssize(prime)-1)
            std::cout << "[ ";
        std::cout << prime.at(static_cast<size_t>(index)) << (index>0? ", ": "]\n");
    }
    return EXIT_SUCCESS;
}
