#include <cstdlib>
#include <cstdint>
#include <array>
#include <algorithm>
#include <iostream>

template <typename T>
void swap(T& first, T& second) {
    if (&first == &second)
        return ;
    T temp{first};
    first = second;
    second = temp;
}

template <typename T, size_t N>
void selSort(std::array<T, N>& arr) {
    if (std::size(arr) <= 1)
        return ;
    for (size_t startIndex{0}; startIndex<std::size(arr)-1; ++startIndex) {
        size_t smallestIndex{startIndex};
        for (size_t currIndex{startIndex+1}; currIndex < std::size(arr); ++currIndex)
            if (arr[currIndex] < arr[smallestIndex])
                smallestIndex = currIndex;
        swap(arr[startIndex], arr[smallestIndex]);
    }
}

template <typename T, size_t N>
void bubbleSort(std::array<T, N>& arr) {
    if (std::size(arr) <= 1)
        return ;
    for (size_t count{0}; count<std::size(arr)-1; ++count)
        for (size_t currIndex{1}; currIndex<std::size(arr)-count; ++currIndex)
            if (arr[currIndex-1] > arr[currIndex])
                swap(arr[currIndex-1], arr[currIndex]);
}

template <typename T, size_t N>
bool isSorted(const std::array<T, N>& arr) {
    if (std::size(arr) > 1)
        for (size_t index{1}; index<std::size(arr); ++index)
            if (arr[index-1]>arr[index])
                return false;
    return true;
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& arr) {
    for (auto it{arr.begin()}; it!=arr.end(); ++it)
        out << (it!=arr.begin()?", ":"") << *it;
    return out;

}

template <typename T, size_t N>
ptrdiff_t binSerach(const std::array<T, N>& arr, T search) {
    size_t min{0};
    size_t max{std::size(arr)-1};
    while (min <= max) {
        size_t mid = (min + max) / 2;
        if      (arr[mid] > search)
            max = mid-1;
        else if (arr[mid] < search)
            min = mid+1;
        else
            return static_cast<ptrdiff_t>(mid);
    }
    return -1;
}

namespace {
    constexpr auto search{4};
};

int main() {
    std::array arr{3, 5, 7, 6, 1};
    std::cout << arr << '\t'
        << "is sorted: "<< std::boolalpha << isSorted(arr) << '\n';
    // bubbleSort(arr);
    std::sort(arr.begin(), arr.end());
    std::cout << arr << '\t'
        << "is sorted: "<< std::boolalpha << isSorted(arr) << '\n'
        << "index of value " << search << " in sorted array is: " << binSerach(arr, search) << '\n';
    return EXIT_SUCCESS;
}


