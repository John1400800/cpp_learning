// C++23 version
#include <cstdlib>   // for EXIT_SUCCESS
#include <algorithm> // for std::max
#include <cmath>     // for std::abs (constexpr in C++23)
#include <iostream>  // for cin, cout

template <typename T>
constexpr T constAbs(T x) {
    return (x < 0) ? -x : x;
}

// Return true if the difference between a and b is within epsilon percent of the larger of a and b
constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
	return (constAbs(a - b) <= (std::max(constAbs(a), constAbs(b)) * relEpsilon));
}

// Return true if the difference between a and b is less than or equal to absEpsilon, or within relEpsilon percent of the larger of a and b
constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (std::abs(a - b) <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

int main() {
    constexpr double a{ .1+.1+.1+.1+.1+.1+.1+.1+.1+.1 };
    constexpr double relEps{ 1e-8 };
    constexpr double absEps{ 1e-12 };
    constexpr bool same{ approximatelyEqualAbsRel(a, 1, absEps, relEps) };
    std::cout << std::boolalpha
        << same << '\n';
    return EXIT_SUCCESS;
}
