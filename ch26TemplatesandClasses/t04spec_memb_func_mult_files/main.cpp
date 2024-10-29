// main.cpp
#include <cstdlib>
#include <iostream>
#include "stor.h"

int main() {
    Storage storFloat{ 0.5f };
    storFloat.print(std::cout);
    static_cast<Storage<double>>(storFloat).print(std::cout);
    return EXIT_SUCCESS;
}
