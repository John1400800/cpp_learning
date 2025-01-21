#include <vector>
#include <iostream>

auto main() -> std::int32_t {
    std::vector<std::vector<std::uint32_t>> vec(3, std::vector(2, 1u));
    for (std::uint32_t i{0}; std::vector<std::uint32_t> &row : vec)
        for (std::uint32_t &val : row)
            val += i++;
    for (const std::vector<std::uint32_t> &row : vec) {
        for (std::uint32_t val : row)
            std::cout << val << ' ';
        std::cout << '\n';
    }
    return EXIT_SUCCESS;
}
