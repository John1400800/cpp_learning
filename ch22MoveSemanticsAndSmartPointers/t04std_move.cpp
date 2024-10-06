#include <cstdlib>
#include <string>
#include <utility>
#include <iostream>

template <typename T>
void mySwapMove(T& a, T&b) {
    T temp{static_cast<T&&>(a)}; // or use std::move
    a = static_cast<T&&>(b);
    b = static_cast<T&&>(temp);
}

int main() {
    std::string x{ "abc" },
                y{ "de" };
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    mySwapMove(x, y);
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    return EXIT_SUCCESS;
}
