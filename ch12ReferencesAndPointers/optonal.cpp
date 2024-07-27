#include <optional>
#include <iostream>

namespace {
    const int       divident        { 4 };
    const int       divisor         { 2 };
}

std::optional <int> doIntDivision(int divident, int divisor);

int main() {
    auto func{ doIntDivision };
    const std::optional<int> result{ func(divident, divisor) };
    if (result.has_value())
        std::cout << result.value() << '\n';
    else
        std::cout << "error\n";
    return EXIT_SUCCESS;
}

std::optional <int> doIntDivision(int divident, int divisor) {
    if (divisor==0)
        return std::nullopt;
    return divident/divisor;
}
