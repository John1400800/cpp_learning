#include <cstdlib>
#include <cstdint>
#include <memory>
#include <utility>
#include <iostream>

class Frac {
    int32_t num_{ 0 };
    int32_t den_{ 1 };
public:
    explicit Frac(int32_t num=0, int32_t den=1)
        : num_{ num }, den_{ den }
    { }

    Frac& operator=(const Frac& other) {
        num_ = other.num_;
        den_ = other.den_;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Frac& f) {
        return out << f.num_ << " / " << f.den_;
    }
};

// Use std::make_unique() instead of creating std::unique_ptr and using new yourself.
int main() {
    // Create a single dynamically allocated Fraction with numerator 3 and denominator 5
    // We can also use automatic type deduction to good effect here
    auto f1{ std::make_unique<Frac>(1, 3) };
    std::cout << *f1 << '\n';
    // Create a dynamically allocated array of Fractions of length 4
    constexpr auto len{ 9 };
    auto fArr{ std::make_unique<Frac[]>(len)};
    for (size_t i{0}; i<len; ++i)
        fArr[i] = Frac{ 1, static_cast<int32_t>(i+1) };
    for (size_t i{0}; i<len; ++i)
        std::cout << (i>0? ",\n": "") << fArr[i];
    std::cout << '\n';
    return EXIT_SUCCESS;
}
