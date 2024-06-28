#include /*<c++/13.2/ */<cstdint>
#include /*<c++/13.2/ */<iostream>
#include /*<c++/13.2/ */<cstdlib>

constexpr bool isEqual(int_fast64_t a, int_fast64_t b) {
    return a==b;
}

int main() {
    int_fast64_t a{}, b{};
    std::cout << "Enter an first integer: ";
    std::cin >> a;
    std::cout << "Enter an second integer: ";
    std::cin >> b;
    std::cout << a << " and " << b << " are ";
    if (a != b)
        std::cout << "not ";
    std::cout << "equal\n";
    return EXIT_SUCCESS;
};

