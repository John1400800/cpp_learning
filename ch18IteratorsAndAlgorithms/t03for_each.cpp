#include <cstdlib>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <iostream>

template <typename T>
void doubleNumber(T& item) {
    item *= 2;
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const T (&arr)[N]) {
    for (size_t i=0; i < N; ++i)
        std::cout << (i!=0?", ":"") << arr[i];
    return out;
}

int main() {
    uint32_t arr[]{ 2, 1, 9, 4, 5 };
    std::for_each(std::begin(arr), std::end(arr), doubleNumber<uint32_t>);
    std::cout << arr << '\n';
    return EXIT_SUCCESS;
}
