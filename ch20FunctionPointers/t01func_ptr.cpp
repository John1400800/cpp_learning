#include <cstdlib>
#include <cstdint>
#include <iterator>
#include <iostream>

template <typename T>
void swap(T& first, T& second) {
    T temp{ first };
    first = second;
    second = temp;
}

template <typename T>
void selSort(T *begin, const T *end, bool (*compFunc)(T&, T&)) {
    for (auto startIt{begin}; startIt!=end; ++startIt) {
        auto swapElemIt{startIt};
        for (auto currIt{startIt+1}; currIt!=end; ++currIt)
            if (compFunc(*swapElemIt, *currIt))
                swapElemIt = currIt;
        swap(*swapElemIt, *startIt);
    }
}

template <typename T>
bool ascending(T& first, T& second) {
    return first > second;
}

int main() {
    uint32_t arr[]{ 2, 5, 3, 1, 4 };
    selSort(std::begin(arr), std::end(arr), ascending);
    return EXIT_SUCCESS;
}
