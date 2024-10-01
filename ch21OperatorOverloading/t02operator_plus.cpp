#include <cstdlib>
#include <cstdint>
#include <iostream>

class MinMax {
    int32_t min_{}, max_{};
public:
    MinMax(int32_t min, int32_t max)
        : min_{min}, max_{max}
    { }
    int32_t min() const {
        return min_;
    }
    int32_t max() const {
        return max_;
    }
    friend MinMax operator+(const MinMax& m1, const MinMax& m2) {
        return MinMax { m1.min_ < m2.min_ ? m1.min_ : m2.min_,
                        m1.max_ > m2.max_ ? m1.max_ : m2.max_ };
    }
    friend MinMax operator+(const MinMax& m, int32_t value) {
        return MinMax { m.min_  < value   ? m.min_  : value,
                        m.max_  > value   ? m.max_  : value };
    }
    friend MinMax operator+(int32_t value, const MinMax& m) {
        return operator+(m, value); // same as m + value
    }
    friend std::ostream& operator<<(std::ostream& out, const MinMax& m) {
        return out << "( " << m.min_ << ", " << m.max_ << " )";
    }
};

int main() {
    MinMax m1{10, 15},
           m2{ 8, 11},
           m3{ 3, 12};
    MinMax mFinal{ m1 + m2 + 5 + 8 + m3 + 16 };
    std::cout << "Result: "<< mFinal << '\n';
    return EXIT_SUCCESS;
}
