#include <cstdlib>
#include <cstdint>
#include <array>
#include <functional>
#include <iostream>

template <typename T, size_t Row, size_t Col>
using ArrayFlat2d = std::array<T, Row * Col>;

template <typename T, size_t Row, size_t Col>
class ArrayView2d {
#if 0
    std::reference_wrapper<ArrayFlat2d<T, Row, Col>> arr_{}; // more safety
#endif
    ArrayFlat2d<T, Row, Col> *arr_{};
public:
    ArrayView2d(ArrayFlat2d<T, Row, Col>& arr)
        : arr_{&arr} {}
    T& operator[](ptrdiff_t i) {
        return arr_[static_cast<size_t>(i)];
    }
    const T& operator[](ptrdiff_t i) const {
        return arr_[static_cast<size_t>(i)];
    }
    T& operator()(size_t row, size_t col) {
        return (*arr_)[row*cols()+col];
    }
    const T& operator()(size_t row, size_t col) const {
        return arr_[row*cols()+col];
    }
    constexpr size_t rows() const {
        return Row;
    }
    constexpr size_t cols() const {
        return Col;
    }
    constexpr size_t size() const {
        return Row * Col;
    }
};

int main() {
    ArrayFlat2d<uint32_t, 3, 4> arr {
        1,  2,  3,  4,
        5,  6,  7,  8,
        9, 10, 11, 12
    };
    ArrayView2d<uint32_t, 3, 4> arrView{ arr };
    std::cout << "rows: " << arrView.rows()
        << ", cols: " << arrView.cols()
        << ", size: " << arrView.size() << '\n';
    for (size_t row{0}; row<arrView.rows(); ++row)
        for (size_t col{0}; col<arrView.cols(); ++col)
            std::cout << (col>0?", ":row>0?"\n":"") << arrView(row, col);
    std::cout << '\n';
    return EXIT_SUCCESS;
}
