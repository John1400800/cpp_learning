#include <cstdlib>
#include <cstdint>
#include <limits>
#include <string>
#include <algorithm>
#include <iostream>

template <typename T>
T& getInput(T& res) {
    while (!(std::cin >> res)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again: ";
    }
    return res;
}

template <typename T>
T getInput() {
    T res;
    while (!(std::cin >> res)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again: ";
    }
    return res;
}

int main() {
    std::cout << "How many names would you like to enter? ";
    size_t length{getInput<size_t>()};
    auto *names = new std::string[length];
    for (size_t i = 0; i < length; ++i)
        std::getline(std::cin >> std::ws, names[i]);
    std::sort(names, names + length);
    for (size_t i = 0; i < length; ++i)
        std::cout << (i > 0 ? ", " : "") << names[i];
    std::cout << std::endl;
    delete[] names;
    return EXIT_SUCCESS;
}
