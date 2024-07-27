#include <cstdlib>
#include <cstdint>
#include <iostream>

/* A few notes:

 * First, just as in the case of an int, when used in an expression, a
 * temporary class object is an rvalue. Thus, such objects can only be used
 * where rvalue expressions are accepted.

 * Second, temporary objects are created at the point of definition, and
 * destroyed at the end of the full expression in which they are defined. A
 * full expression is an expression that is not a subexpression.
 */

class IntegerPair {
    int32_t m_x{};
    int32_t m_y{};
public:
    IntegerPair(int32_t iniX, int32_t iniY) : m_x{ iniX }, m_y{ iniY } {}
    int32_t x() const { return m_x; }
    int32_t y() const { return m_y; }
};

IntegerPair ret1(int32_t x, int32_t y) {
    IntegerPair pair{ x, y };
    return pair;
}

IntegerPair ret2(int32_t x, int32_t y) {
    return IntegerPair{ x, y };
}

IntegerPair ret3(int32_t x, int32_t y) {
    return { x, y };
}

std::ostream& operator<<(std::ostream& out, IntegerPair pair) {
    std::cout << "x= " << pair.x() << ", "
        << "y= " << pair.y();
    return out;
}

int main() {
    std::cout << ret1(1, 2) << '\n'
        << ret2(3, 4) << '\n'
        << ret3(5, 6) << '\n';
    return EXIT_SUCCESS;
}
