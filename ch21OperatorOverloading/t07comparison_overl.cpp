#include <cstdlib>
#include <cstdint>
#include <array>
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
public:
    using frac_t = int32_t;
    enum Component : size_t {
        Num, Den,
        maxComponent
    };

    Fraction(frac_t num=0, frac_t den=1);

    frac_t&   operator[](Component index);
    frac_t    operator[](Component index) const;
    Fraction  operator+ () const;
    Fraction  operator- () const;
    Fraction& operator*=(const Fraction&);
    Fraction& operator/=(const Fraction&);
    Fraction& operator+=(const Fraction&);
    Fraction& operator-=(const Fraction&);
    Fraction& operator++();
    Fraction& operator--();
    Fraction  operator++(int32_t);
    Fraction  operator--(int32_t);

    template <Component C>
    frac_t  get() const {
        static_assert( C < maxComponent,
                       "Invalid template argument! Must be 0 or 1." );
        return (*this)[C];
    }

    template <Component C>
    frac_t& get() {
        static_assert( C < maxComponent,
                       "Invalid template argument! Must be 0 or 1." );
        return (*this)[C];
    }

    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&);
private:
    std::array<frac_t, 2> comps{ 0, 1 };
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
        << "++(" << f1 << ") == " << ++f1 << '\n'
        << "--(" << f1 << ") == " << --f1 << '\n'
        << "(" << f1 << ")++ == " << f1++ << ", f == " << f1 << '\n'
        << "(" << f1 << ")-- == " << f1-- << ", f == " << f1 << '\n';
    return EXIT_SUCCESS;
}

Fraction::Fraction(Fraction::frac_t num, Fraction::frac_t den)
    : comps{num, den}
{
    if (den == 0)
        throw std::invalid_argument("denumerator cannotbe zero.");
}

template <>
Fraction::frac_t Fraction::get<Fraction::Num>() const {
    return (*this)[Fraction::Num];
}

template <>
Fraction::frac_t Fraction::get<Fraction::Den>() const {
    return (*this)[Fraction::Den];
}

template <>
Fraction::frac_t& Fraction::get<Fraction::Num>() {
    return (*this)[Fraction::Num];
}

template <>
Fraction::frac_t& Fraction::get<Fraction::Den>() {
    return (*this)[Fraction::Den];
}


Fraction::frac_t& Fraction::operator[](Fraction::Component index) {
    return comps[index];
}

Fraction::frac_t Fraction::operator[](Fraction::Component index) const {
    return comps[index];
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    return f1.get<Fraction::Num>() * f2.get<Fraction::Den>()
        == f2.get<Fraction::Num>() * f1.get<Fraction::Den>();
}
bool operator!=(const Fraction& f1, const Fraction& f2) {
    return !(f1 == f2);
}
bool operator> (const Fraction& f1, const Fraction& f2) {
    return f1.get<Fraction::Num>() * f2.get<Fraction::Den>()
        > f2.get<Fraction::Num>() * f1.get<Fraction::Den>();
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
    return Fraction{ -get<Fraction::Num>(),
                      get<Fraction::Den>() };
}

Fraction& Fraction::operator++() {
    return *this += 1;
}

Fraction& Fraction::operator--() {
    return *this -= 1;
}

Fraction Fraction::operator++(int32_t) {
    return ++*this - 1; // Fraction temp{*this};
                        // ++*this;
                        // return temp;
}

Fraction Fraction::operator--(int32_t) {
    return --*this + 1; // Fraction temp{*this};
                        // --*this;
                        // return temp;
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
    return Fraction{ f1.get<Fraction::Num>() * f2.get<Fraction::Num>(),
                     f1.get<Fraction::Den>() * f2.get<Fraction::Den>() };
}

Fraction operator/ (const Fraction& f1, const Fraction& f2) {
    return Fraction{ f1.get<Fraction::Num>() * f2.get<Fraction::Den>(),
                     f1.get<Fraction::Den>() * f2.get<Fraction::Num>() };
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    Fraction::frac_t lcm{ utils::lcm(f1.get<Fraction::Den>(), f2.get<Fraction::Den>()) };
    return Fraction{ (f1.get<Fraction::Num>() * lcm / f1.get<Fraction::Den>()
                      + f2.get<Fraction::Num>() * lcm / f2.get<Fraction::Den>())
                    , lcm };
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    return f1 + -f2;
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    if (frac.get<Fraction::Num>() == 0)
        return out << 0;
    Fraction::frac_t f_gcd{ utils::gcd(frac.get<Fraction::Num>(), frac.get<Fraction::Den>()) };
    if (frac.get<Fraction::Den>() == f_gcd)
        return out << frac.get<Fraction::Num>() / f_gcd;
    if (frac.get<Fraction::Den>() * f_gcd < 0)
        f_gcd = -f_gcd;
    return out << frac.get<Fraction::Num>() / f_gcd
        << "/" << frac.get<Fraction::Den>() / f_gcd;
}

std::istream& operator>>(std::istream& in, Fraction& frac) {
    Fraction::frac_t newNum, newDen;
    char delim;
    in >> newNum >> delim >> newDen;
    if (in && delim == '/')
        frac = Fraction{newNum, newDen};
    else
        in.setstate(std::ios_base::failbit);
    return in;
}
