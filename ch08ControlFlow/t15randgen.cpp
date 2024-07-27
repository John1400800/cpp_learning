#include "t15randgen.hpp"
#include <cstdlib>
#include <iostream>

int main() {
    std::cout << Random::get(1, 6) << '\n';
    return EXIT_SUCCESS;
}
