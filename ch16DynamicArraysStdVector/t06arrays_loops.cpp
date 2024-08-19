#include <cstdint>      /* <c++/13.2/ */
#include <cstdlib>      /* <c++/13.2/ */
#include <vector>       /* <c++/13.2/ */
#include <type_traits>  /* <c++/13.2/ */
#include <iostream>     /* <c++/13.2/ */

template <typename T>
constexpr std::size_t toUZ(T value) {
    static_assert(std::is_integral<T>() || std::is_enum<T>());
    return static_cast<std::size_t>(value);
}

template <typename T>
T calcAverage(const std::vector<T>& vec) {
    T sum{};
    for (auto index{std::ssize(vec)-1}; index>=0; --index)
        sum += vec[toUZ(index)];
    return sum / static_cast<T>(vec.size());
}

int main() {
    std::vector testScore{ 84, 92, 76, 81, 56 };
    std::cout << "Average score: " << calcAverage(testScore) << '\n';
    return EXIT_SUCCESS;
}
