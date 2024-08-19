#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <vector>

#if 0
namespace Students {
    enum Names : uint16_t {
        kenny,
        kyle,
        stan,
        butters,
        cartman,

        max_students
    }
}
#else 
enum class StudentNames : uint16_t { // However, if you’re going to be doing
    kenny,                           // a lot of enumerator to integral
    kyle,                            // conversions, it’s probably better to
    stan,                            // just use a standard enum inside a
    butters,                         // namespace (or class).
    cartman,

    max_students
};
#endif

constexpr auto operator+(StudentNames name) noexcept {
    return static_cast<size_t>(name);
}

int main() {
    std::vector<uint16_t> testScores(+StudentNames::max_students);
    testScores[+StudentNames::stan] = 76;
    return EXIT_SUCCESS;
}
