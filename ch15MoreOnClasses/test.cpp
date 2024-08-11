#include <cstdint>
#include <cstdlib>
#include <iostream>

template <typename T>
struct Something {
    T member;
};

template <typename T>
Something(T) -> Something<T>;

int main() {
    Something something{ 2 };
    std::cout << something.member << '\n';
    return EXIT_SUCCESS;
}
