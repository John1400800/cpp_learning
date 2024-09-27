#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <iterator>
#include <functional>
#include <iostream>

template <typename T>
void swap(T& first, T& second) {
    T temp{ first };
    first = second;
    second = temp;
}

#if 0
template <typename T>
using ValidateFunction = bool(*)(const T&, const T&);
#else
template <typename T>
using ValidateFunction = std::function<bool(const T&, const T&)>;
#endif

template <typename T>
void selSort(T *begin, const T *end,
             ValidateFunction<T> compFunc=[](const T& a, const T& b){ return a > b; }) {
    for (auto startIt{begin}; startIt!=end; ++startIt) {
        auto swapElemIt{startIt};
        for (auto currIt{startIt+1}; currIt!=end; ++currIt)
            if (compFunc(*swapElemIt, *currIt))
                swapElemIt = currIt;
        swap(*swapElemIt, *startIt);
    }
}

template <typename T>
bool ascending(const T& first, const T& second) {
    return first > second;
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const T (&arr)[N]) {
    for (size_t i{0}; i<N; ++i)
        std::cout << (i!=0?", ":"") << arr[i];
    return out;
}

std::ostream& operator<<(std::ostream& out, const char* arr) {
    return out.write(arr, static_cast<std::streamsize>(std::strlen(arr)));
}

int main() {
    uint32_t arr[]{ 2, 5, 3, 1, 4 };
    std::cout << arr << '\n';
    selSort(std::begin(arr), std::end(arr));
    std::cout << arr << '\n';
    return EXIT_SUCCESS;
}
