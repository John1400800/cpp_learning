#include <cstdlib>
#include <cstdint>
#include <limits>
#include <iostream>

class Foo {
    int32_t x{};
    int32_t y{};
public:
    // member initializer list
    Foo(int32_t newX, int32_t newY) : x{ newX }, y{ newY } {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
    void print() const {
        std::cout << "Foo(" << x << ", " << y << ")\n";
    }
};

int32_t getNumber();

int main() {
    const Foo foo{ getNumber(), getNumber() };
    foo.print();
    return EXIT_SUCCESS;
}

int32_t getNumber() {
    int32_t inputNum{};
    std::cout << "Enter number: ";
    for (;;) {
        std::cin >> inputNum;
        if (!std::cin) {
            if (std::cin.eof())
                exit(0);
            std::cin.clear();
            std::cout << "Try again: ";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return inputNum;
    }
}

