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
    Fraction(int32_t num=0, int32_t den=1);

    int32_t num() const { return num_; }
    int32_t den() const { return den_; }

    Fraction  operator+ () const;
    Fraction  operator- () const;
    Fraction& operator*=(const Fraction&);
    Fraction& operator/=(const Fraction&);
    Fraction& operator+=(const Fraction&);
    Fraction& operator-=(const Fraction&);
    Fraction& operator++();
    Fraction& operator--();

    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&);
};

bool     operator==(const Fraction&, const Fraction&);
bool     operator!=(const Fraction&, const Fraction&);
bool     operator> (const Fraction&, const Fraction&);
bool     operator< (const Fraction&, const Fraction&);
bool     operator>=(const Fraction&, const Fraction&);
bool     operator<=(const Fraction&, const Fraction&);

Fraction operator* (const Fraction&, const Fraction&);
Fraction operator/ (const Fraction&, const Fraction&);
Fraction operator+ (const Fraction&, const Fraction&);
Fraction operator- (const Fraction&, const Fraction&);

int main() {
    std::cout << "Enter fraction 1: ";
    Fraction f1{};
    std::cin >> f1;
    std::cout << "Enter fraction 2: ";
    Fraction f2{};
    std::cin >> f2;
    std::cout
        << f1 << " +  " << f2 << " == "                <<  f1 +  f2  << '\n'
        << f1 << " -  " << f2 << " == "                <<  f1 -  f2  << '\n'
        << f1 << " *  " << f2 << " == "                <<  f1 *  f2  << '\n'
        << f1 << " /  " << f2 << " == "                <<  f1 /  f2  << '\n'
        << f1 << " == " << f2 << std::boolalpha << ' ' << (f1 == f2) << '\n'
        << f1 << " != " << f2                   << ' ' << (f1 != f2) << '\n'
        << f1 << " >  " << f2                   << ' ' << (f1 >  f2) << '\n'
        << f1 << " <  " << f2                   << ' ' << (f1 <  f2) << '\n'
        << f1 << " >= " << f2                   << ' ' << (f1 >= f2) << '\n'
        << f1 << " <= " << f2                   << ' ' << (f1 <= f2) << '\n'
        << "++(" << f1 << ") == ";
    std::cout << ++f1 << '\n'
        << "--(" << f1 << ") == ";
    std::cout << --f1 << '\n';
    return EXIT_SUCCESS;
}

Fraction::Fraction(int32_t num, int32_t den)
    : num_{num}, den_{den}
{
    if (den_ == 0)
        throw std::invalid_argument("denumerator cannotbe zero.");
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    return f1.num() * f2.den() == f2.num() * f1.den();
}
bool operator!=(const Fraction& f1, const Fraction& f2) {
    return !(f1 == f2);
}
bool operator> (const Fraction& f1, const Fraction& f2) {
    return f1.num() * f2.den() > f2.num() * f1.den();
}
bool operator< (const Fraction& f1, const Fraction& f2) {
    return f2 > f1;
}
bool operator>=(const Fraction& f1, const Fraction& f2) {
    return !(f1 < f2);
}
bool operator<=(const Fraction& f1, const Fraction& f2) {
    return !(f1 > f2);
}

Fraction  Fraction::operator+ () const {
    return *this;                     
}                                     
                                      
Fraction  Fraction::operator- () const {
    return Fraction{ -num(),
                      den() };
}

Fraction& Fraction::operator++() {
    return *this += 1;
}

Fraction& Fraction::operator--() {
    return *this -= 1;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    return *this = *this * other;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    return *this = *this / other;
}

Fraction& Fraction::operator+=(const Fraction& other) {
    return *this = *this + other;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    return *this = *this - other;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction{ f1.num() * f2.num(),
                     f1.den() * f2.den() };
}

Fraction operator/ (const Fraction& f1, const Fraction& f2) {
    return Fraction{ f1.num() * f2.den(),
                     f1.den() * f2.num() };
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    int32_t lcm{ utils::lcm(f1.den(), f2.den()) };
    return Fraction{ f1.num() * lcm / f1.den() + f2.num() * lcm / f2.den(),
                     lcm };
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    return f1 + -f2;
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    if (frac.num_ == 0)
        return out << 0;
    int32_t f_gcd{ utils::gcd(frac.num_, frac.den_) };
    if (frac.den_ == f_gcd)
        return out << frac.num_ / f_gcd;
    if (frac.den_ * f_gcd < 0)
        f_gcd = -f_gcd;
    return out << frac.num_ / f_gcd
        << "/" << frac.den_ / f_gcd;
}
std::istream& operator>>(std::istream& in, Fraction& frac) {
    int32_t newNum, newDen;
    char delim;
    in >> newNum >> delim >> newDen;
    if (in && delim == '/')
        frac = Fraction{newNum, newDen};
    else
        in.setstate(std::ios_base::failbit);
    return in;
}
