#include <cstdint>
#include <cstdlib>
#include <iostream>

class Pair {
    int32_t m_x{};
    int32_t m_y{};
public:
    constexpr Pair(int32_t x, int32_t y) : m_x{ x }, m_y{ y } {}
    constexpr int32_t greater() const {
        return m_x > m_y ? m_x : m_y;
    }
};

int main() {
    constexpr Pair pair{1, 2};
    constexpr int32_t grtr{ pair.greater() };
    std::cout << grtr << '\n';
    return EXIT_SUCCESS;
}
