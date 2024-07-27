#include <cstdint>
#include <cstdlib>
#include <string_view>
#include <iostream>

#if 1
#define PAIR_DECLARE
// template <typename T, typename U>
template <typename T=uint16_t, typename U=uint16_t> // default T and U to type uint16_t for exaple `Pair p;`
struct Pair {
    T first{};
    U second{};
};

struct Foo {
    Pair<uint16_t, uint16_t> p1{1, 2};
};

/* For advanced readers:
 * Non-aggregates don’t need deduction guides in C++17
 * because the presence of a constructor serves the same purpose.
 */

/* Here's a deduction guide for our Pair (needed in C++17 only)
 * Pair objects initialized with arguments of type T and U should deduce to Pair<T, U>
 */
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

template <typename T=double>
using Coord = Pair<T, T>;
#endif

constexpr auto max(const Pair<auto, auto>& p) {
    return (p.first > p.second) ? p.first : p.second;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Coord<T>& coord) {
    std::cout << coord.first << ' ' << coord.second << '\n';
    return out;
}

int main() {
#ifdef PAIR_DECLARE
    std::cout << max(Pair { "hello", "world" } ) << '\n';
    std::cout << max(Pair {} );
#else
    std::cout << max(std::pair { "hello", "world" } ) << '\n';
#endif
    using Point = Pair<double, double>;
    std::cout << max(Point { 12.25, 13.2 }) << '\n';
    std::cout << Coord{ 1.2, 3.2 } << '\n';
    return EXIT_SUCCESS;
}

