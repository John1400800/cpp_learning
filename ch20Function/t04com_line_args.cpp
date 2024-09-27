#include <cstdlib>
#include <cstdint>
#include <iostream>

int main(int argc, char *argv[]) {
    for (auto i{0}; i < argc; ++i)
        std::cout << i << ' ' << argv[i] << '\n';
    return EXIT_SUCCESS;
}
