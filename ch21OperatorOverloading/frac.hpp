#ifndef FRAC_H
#define FRAC_H

#include <cstdlib>
#include <cstdint>
#include <array>
#include <iostream>

namespace utils {
    template <typename T>
    constexpr T abs(T a);

    template <typename T>
    constexpr void swap(T& a, T& b);

    constexpr int32_t gcd(int32_t a, int32_t b);
    constexpr int32_t lcm(int32_t a, int32_t b);
}

class Fraction {
public:
    using frac_t = int32_t;

    enum Component : size_t {
        Num, Den,
        maxComponent
    };

    Fraction(frac_t num=0, frac_t den=1);

    const frac_t&   operator[](Component index) const;
    Fraction  operator+ () const;
    Fraction  operator- () const;

    explicit operator int32_t() const;
    operator bool()             const;
    operator double()           const;

    template <typename T>
    Fraction& operator*=(const T&);

    template <typename T>
    Fraction& operator/=(const T&);

    template <typename T>
    Fraction& operator+=(const T&);

    template <typename T>
    Fraction& operator-=(const T&);

    Fraction& operator++();
    Fraction& operator--();
    Fraction  operator++(int32_t);
    Fraction  operator--(int32_t);

    template <Component C>
    frac_t  get() const {
        static_assert( C < maxComponent, "Invalid template argument! Must be 0 or 1." );
        return (*this)[C];
    }

    friend std::istream& operator>>(std::istream&, Fraction&);
private:
    std::array<frac_t, 2> comps{ 0, 1 };

    frac_t&   operator[](Component index);

    template <Component C>
    frac_t& get() {
        static_assert( C < maxComponent, "Invalid template argument! Must be 0 or 1." );
        return (*this)[C];
    }
};

template <typename T, typename U>
bool     operator==(const T&, const U&);

template <typename T, typename U>
bool     operator!=(const T&, const U&);

template <typename T, typename U>
bool     operator> (const T&, const U&);

template <typename T, typename U>
bool     operator< (const T&, const U&);

template <typename T, typename U>
bool     operator>=(const T&, const U&);

template <typename T, typename U>
bool     operator<=(const T&, const U&);

template <typename T, typename U>
Fraction operator* (const T&, const U&);

template <typename T, typename U>
Fraction operator/ (const T&, const U&);

template <typename T, typename U>
Fraction operator+ (const T&, const U&);

template <typename T, typename U>
Fraction operator- (const T&, const U&);

std::ostream& operator<<(std::ostream&, const Fraction&);

#endif // FRAC_H
