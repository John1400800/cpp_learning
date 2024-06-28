#include <cstdint>
#include <cstdlib>
#include <cassert>
#include <limits>
#include <iostream>

using std::int64_t;

constexpr int64_t powint_safe(int64_t base, int64_t exp) {
    assert(exp >= 0 && "powint_safe: exp parameter has negative value");
    if (base == 0)
        return (exp == 0) ? 1 : 0;
    bool isNegativeResult { false };
    if (base < 0) {
        base = -base;
        isNegativeResult = (exp & 1);
    }
    int64_t result{ 1 };
    while (exp > 0) {
        if (exp & 1) {
            if (result > std::numeric_limits<int64_t>::max() / base) {
                std::cerr << "powint_safe(): result overflowed\n";
                return std::numeric_limits<int64_t>::max();
            }
            result *= base;
        }
        exp /= 2;
        if (exp > 0 && base > std::numeric_limits<int64_t>::max() / base) {
            std::cerr << "powint_safe(): base overflowed\n";
            return std::numeric_limits<int64_t>::max();
        }
        base *= base;
    }
    return isNegativeResult ? -result : result;
}

int main() {
    std::cout << powint_safe(70, 12) << '\n';
    return EXIT_SUCCESS;
}
