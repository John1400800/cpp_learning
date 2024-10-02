#include <cstdlib>
#include <cstdint>
#include <array>
#include <iostream>
#include "frac.hpp"

namespace utils {
    template <>
    constexpr int32_t abs(int32_t a) {
        return a < 0 ? -a : a;
    }

    template <>
    constexpr void swap(int32_t& a, int32_t& b) {
        int32_t temp{a};
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


Fraction::frac_t& Fraction::operator[](Fraction::Component index) {
    return comps[index];
}

Fraction::frac_t Fraction::operator[](Fraction::Component index) const {
    return comps[index];
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

template <>
Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction{ f1.get<Fraction::Num>() * f2.get<Fraction::Num>(),
                     f1.get<Fraction::Den>() * f2.get<Fraction::Den>() };
}

template <>
Fraction operator*(const Fraction& f1, const Fraction::frac_t& f2) {
    return Fraction{ f1.get<Fraction::Num>() * f2,
                     f1.get<Fraction::Den>() };
}

template <>
Fraction operator*(const Fraction::frac_t& f1, const Fraction& f2) {
    return f2 * f1;
}

template <>
Fraction& Fraction::operator*=(const Fraction& other) {
    return *this = *this * other;
}

template <>
Fraction& Fraction::operator*=(const Fraction::frac_t& other) {
    return *this = *this * other;
}

template <>
Fraction operator/ (const Fraction& f1, const Fraction& f2) {
    return Fraction{ f1.get<Fraction::Num>() * f2.get<Fraction::Den>(),
                     f1.get<Fraction::Den>() * f2.get<Fraction::Num>() };
}

template <>
Fraction operator/ (const Fraction& f1, const Fraction::frac_t& f2) {
    return Fraction{ f1.get<Fraction::Num>(),
                     f1.get<Fraction::Den>() * f2 };
}

template <>
Fraction operator/ (const Fraction::frac_t& f1, const Fraction& f2) {
    return Fraction{ f1 * f2.get<Fraction::Den>(),
                     f2.get<Fraction::Num>() };
}

template <>
Fraction& Fraction::operator/=(const Fraction& other) {
    return *this = *this / other;
}

template <>
Fraction& Fraction::operator/=(const Fraction::frac_t& other) {
    return *this = *this / other;
}

template <>
Fraction operator+(const Fraction& f1, const Fraction& f2) {
    Fraction::frac_t lcm{ utils::lcm(f1.get<Fraction::Den>(), f2.get<Fraction::Den>()) };
    return Fraction{ (f1.get<Fraction::Num>() * lcm / f1.get<Fraction::Den>()
                      + f2.get<Fraction::Num>() * lcm / f2.get<Fraction::Den>())
                    , lcm };
}

template <>
Fraction operator+(const Fraction& f1, const Fraction::frac_t& f2) {
    return Fraction{ f1.get<Fraction::Num>() + f2 * f1.get<Fraction::Den>(),
                     f1.get<Fraction::Den>() };
}

template <>
Fraction operator+(const Fraction::frac_t& f1, const Fraction& f2) {
    return f2 + f1;
}

template <>
Fraction& Fraction::operator+=(const Fraction& other) {
    return *this = *this + other;
}

template <>
Fraction& Fraction::operator+=(const Fraction::frac_t& other) {
    return *this = *this + other;
}

template <>
Fraction operator-(const Fraction& f1, const Fraction& f2) {
    return f1 + -f2;
}

template <>
Fraction operator-(const Fraction& f1, const Fraction::frac_t& f2) {
    return f1 + -f2;
}

template <>
Fraction operator-(const Fraction::frac_t& f1, const Fraction& f2) {
    return f1 + -f2;
}

template <>
Fraction& Fraction::operator-=(const Fraction& other) {
    return *this = *this - other;
}

template <>
Fraction& Fraction::operator-=(const Fraction::frac_t& other) {
    return *this = *this - other;
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
    return ++*this - 1;
}

Fraction Fraction::operator--(int32_t) {
    return --*this + 1;
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
