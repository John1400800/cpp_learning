#include <cstdlib>
#include <iostream>

#define PrintExpr(Expr)                 \
do {                                    \
    std::cout<<#Expr": "<<(Expr)<<'\n'; \
} while (false)

#define MFactBody(number)               \
do {                                    \
    auto product{ 1 };                  \
    for (auto i{(number)}; i>0; --i)    \
        product *= i;                   \
    return product;                     \
} while(false)

template <auto number>
constexpr auto factorial() {
    static_assert(number >= 0, "num must be non-negative");
    MFactBody(number);
}

constexpr auto factorial(auto number) {
    if (number < 0)
        throw std::invalid_argument("num must be non-negative");
    MFactBody(number);
}

int main() {
    PrintExpr(factorial<3>());
    PrintExpr(factorial<5>());
    PrintExpr(factorial(3));
    PrintExpr(factorial(5));
    const auto foo{ 2 };
    [[maybe_unused]]
    constexpr auto bar{ factorial(foo) };
    [[maybe_unused]]
    constexpr auto baz{ factorial<foo>() };
    return EXIT_SUCCESS;
}
