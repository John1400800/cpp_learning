#include <cstdlib>
#include <cmath>
#include <iostream>

int main() {
    std::cout << "Enter a number: ";
    double num{};
    std::cin >> num;
    try {
        if (num < 0.0)
            throw "Can not take sqrt of negative number";
        std::cout << "THe sqrt of " << num << " is " << sqrt(num) << '\n';
    }
    catch (double) {
        ;
    }
    // catch (const char *exception) {
    //     std::cerr << "Error: " << exception << '\n';
    // }
    return EXIT_SUCCESS;
}
