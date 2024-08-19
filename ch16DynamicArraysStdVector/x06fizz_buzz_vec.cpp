#include <cstdint>      /* <c++/13.2/ */
#include <cstdlib>      /* <c++/13.2/ */
#include <string_view>  /* <c++/13.2/ */
#include <vector>       /* <c++/13.2/ */
#include <iostream>     /* <c++/13.2/ */

void fizzBuzz(uint32_t number) {
    static const std::vector<uint32_t> divisors      { 3, 5, 7, 11, 13, 17, 19 };
    static const std::vector<std::string_view> words { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
    bool printed{ false };
    for (size_t index{0}; index < divisors.size(); ++index)
        if (number % divisors[index] == 0) {
            std::cout << words[index];
            printed = true;
        }
    if (!printed)
        std::cout << number;
    std::cout << '\n';
}

int main() {
    for (uint32_t number{0}; number <= 150; ++number)
        fizzBuzz(number);
    return EXIT_SUCCESS;
}
