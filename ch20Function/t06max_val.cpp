#include <cstdlib>
#include <cstdint>
#include <array>
#include <algorithm>
#include <iostream>

struct Student {
    std::string_view    name  {};
    uint32_t            points{};
};

int main() {
    constexpr std::array<Student, 8> arr{{
        { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 },
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } 
    }};
    const auto best{std::max_element(arr.begin(), arr.end(),
                        [](const Student& a, const Student& b) ->  bool {
                            return a.points < b.points;
                        }
    )};
    std::cout << best->name << "is the best student\n";
    return EXIT_SUCCESS;
}
