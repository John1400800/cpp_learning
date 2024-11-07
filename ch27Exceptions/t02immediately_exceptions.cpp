#include <cstdlib>
#include <iostream>

int main() {
    try {
        throw 4.5;
        std::cout << "This never prints\n";
    } catch (double num) {
        std::cerr << "We caught a double of value: " << num << '\n';
    }
    return EXIT_SUCCESS;
}
