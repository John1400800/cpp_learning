#include <cstdlib>
#include <cstdint>
#include <string>
#include <iostream>

int main() {
    try {
        throw -1;
    } catch (double) {
        std::cerr << "We caught an exception of type double\n";
    } catch (int32_t num) {
        std::cerr << "We caugth an int exception with value: " << num << '\n';
    } catch (std::string str) {
        std::cerr << "We caught an int exception of type std::string\n";
    }
    std::cout << "continuing on our merry way\n";
    return EXIT_SUCCESS;
}
