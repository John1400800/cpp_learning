#include <cstdlib>
#include <cstdint>
#include <string>
#include <iomanip>
#include <iostream>

inline namespace Settings {
    constexpr size_t rows{3};
    constexpr size_t cols{4};
    size_t digInArr{std::to_string(rows*cols).length()};
}

int main() {
    // allocate
    using namespace Settings;
    uint32_t **arr2{new uint32_t*[rows]};
    for (size_t row{0}; row<rows; ++row) {
        arr2[row] = new uint32_t[cols];
        for (size_t col{0}; col<cols; ++col)
            arr2[row][col] = static_cast<uint32_t>(col+cols*row);
    }
    // print
    for (size_t row{0}; row<rows; ++row) {
        std::cout << (row==0?"{ ":" },\n  ");
        for (size_t col{0}; col<cols; ++col) {
            std::cout << (col==0?"{ ":", ") << std::setw(digInArr) << arr2[row][col];
        }
    }
    std::cout << " } }\n";
    // clear
    for (size_t row{rows}; row>0; --row) {
        delete[] arr2[row-1];
        arr2[row-1] = nullptr;
    }
    delete[] arr2;
    arr2 = nullptr;
    return EXIT_SUCCESS;
}
