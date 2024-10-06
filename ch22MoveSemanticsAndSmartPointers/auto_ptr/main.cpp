#include <cstdlib>
#include <cstdint>
#include <array>
#include <iostream>
#include <functional>

#include "auto_ptr.h"
#include "elem.h"
#include "utils.h"

constexpr size_t len{ 4 };
constexpr std::array<uint32_t, len> iniArr{ 4, 1, 3, 2 };

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, Auto_ptr<Elem<T>> (&arr)[N]) {
    for (size_t i{0}; i < N; ++i)
        std::cout << (i > 0 ? ", " : "") << *arr[i];
    return out;
}

int main() {
    Auto_ptr<Elem<uint32_t>> arr[len];
    for (size_t i{0}; i < len; ++i)
        arr[i] = Auto_ptr<Elem<uint32_t>>{ new Elem<uint32_t>{iniArr[i]} };

    std::cout << arr << '\n';
    
    std::function<bool(const Auto_ptr<Elem<uint32_t>>&,
                       const Auto_ptr<Elem<uint32_t>>&)> comp {
        [](const Auto_ptr<Elem<uint32_t>>& a,
           const Auto_ptr<Elem<uint32_t>>& b) {
            return *a < *b;
        }};
    
    // Передаем указатели на массив как итераторы
    selSort(arr, arr + len, comp);
    
    std::cout << arr << '\n';
    return EXIT_SUCCESS;
}
