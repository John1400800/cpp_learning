// main.cpp
#include <cstdlib>
#include <cstdint>
#include <array>
#include <functional>
#include <iostream>

#include "elem.h"

// #define USE_UTILS
// #define USE_AUTO_PTR

#ifdef USE_UTILS
#include "utils.h"
#else
#include <algorithm>
#endif

#ifdef USE_AUTO_PTR
#include "auto_ptr.h"
template<typename T>
using SmrtPtr = Auto_ptr<T>;
#else
#include <memory>
template<typename T>
using SmrtPtr = std::unique_ptr<T>;
#endif

template <typename T, typename Compare>
void sort(T* begin, T* end, Compare comp) {
#ifdef USE_UTILS
    selSort(begin, end, comp);
#else
    std::sort(begin, end, comp);
#endif
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<SmrtPtr<Elem<T>>, N>& arr) {
    for (size_t i{0}; i < N; ++i)
        out << (i > 0 ? ", " : "") << *arr[i];
    return out;
}

constexpr size_t len{4};
constexpr std::array<uint32_t, len> iniArr{4, 1, 3, 2};

int main() {
    std::array<SmrtPtr<Elem<uint32_t>>, len> arr;
    for (size_t i{0}; i < len; ++i)
        arr[i] = SmrtPtr<Elem<uint32_t>>{new Elem<uint32_t>{iniArr[i]}};

    std::cout << "Before sorting: " << arr << '\n';

    // Лямбда для сравнения
    auto comp = [](const SmrtPtr<Elem<uint32_t>>& a, const SmrtPtr<Elem<uint32_t>>& b) {
        return *a < *b;
    };

    // Вызов функции сортировки
    sort(arr.data(), arr.data() + arr.size(), comp);

    std::cout << "After sorting: " << arr << '\n';
    return EXIT_SUCCESS;
}
