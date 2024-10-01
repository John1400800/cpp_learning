#include <cstdlib>
#include <cstdint>
#include <iostream>

namespace utils {
    template <typename T>
    constexpr T abs(T a) {
        return a < 0 ? -a : a;
    }
    template <typename T>
    constexpr void swap(T& a, T& b) {
        T temp{a};
        a = b;
        b = temp;
    }
    constexpr int32_t gcd(int32_t a, int32_t b) {
        while (b != 0) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
    constexpr int32_t lcm(int32_t a, int32_t b) {
        return abs(a * b) / gcd(a, b);
    }
}

class Fraction {
    int32_t num_{0};
    int32_t den_{1};
public:
    constexpr Fraction(int32_t num=0, int32_t den=1)
        : num_{num}, den_{den}
    {
        if (den_ == 0)
            throw std::invalid_argument("denumerator cannotbe zero.");
    }
    Fraction operator*(const Fraction& other) const {
        return Fraction{ num_ * other.num_,
                         den_ * other.den_ };
    }
    Fraction operator+(const Fraction& other) const {
        int32_t lcm{ utils::lcm(den_, other.den_) };
        return Fraction{ num_ * lcm / den_ + other.num_ * lcm / other.den_,
                         lcm };
    }
    Fraction& operator*=(const Fraction& other) {
        return *this = *this * other;
    }
    Fraction& operator+=(const Fraction& other) {
        return *this = *this + other;
    }
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
        if (frac.num_ == 0)
            return out << 0;
        int32_t f_gcd{ utils::gcd(frac.num_, frac.den_) };
        if (frac.den_ == f_gcd)
            return out << frac.num_ / f_gcd;
        return out << frac.num_ / f_gcd
            << "/" << frac.den_ / f_gcd;
    }
    friend std::istream& operator>>(std::istream& in, Fraction& frac) {
        int32_t newNum, newDen;
        char delim;
        in >> newNum >> delim >> newDen;
        if (in && delim == '/')
            frac = Fraction{newNum, newDen};
        else
            in.setstate(std::ios_base::failbit);
        return in;
    }
};

int main() {
    std::cout << "Enter fraction 1: ";
    Fraction f1{};
    std::cin >> f1;
    std::cout << "Enter fraction 2: ";
    Fraction f2{};
    std::cin >> f2;
    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << '\n';
    return EXIT_SUCCESS;
}
