// main.cpp
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include "array.h"

int main() {
    StaticArray<uint32_t, 3> arr;
    for (size_t i{0}; i<arr.size(); ++i)
        arr[i] = static_cast<uint32_t>(i*2+1);
    std::cout << arr << '\n';
}
