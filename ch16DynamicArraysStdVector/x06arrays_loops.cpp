#include <cstdint>  /* <c++/13.2/ */
#include <cstdlib>  /* <c++/13.2/ */
#include <vector>   /* <c++/13.2/ */
#include <iostream> /* <c++/13.2/ */

template <typename T>
T getMax(const std::vector<T>& vec) {
    T max{};
    for (size_t index{0}; index < std::size(vec); ++index)
        if (vec[index] > max)
            max = vec[index];
    return max;
}

int main() {
    std::vector testScore{ 84, 92, 76, 81, 56 };
    std::cout << "Max score: " << getMax(testScore) << '\n';
    return EXIT_SUCCESS;
}
