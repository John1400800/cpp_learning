#include <cstdlib>
#include <optional>
#include <iomanip>
#include <iostream>

template <typename T>
constexpr T abs(T a) {
    return a < 0 ? -a : a;
}

constexpr bool isdigit(char ch) {
    return ch >= '0' && ch <= '9';
}

template <typename T>
T customStod(std::string_view str) {
    T res{0};
    bool isNegative{false};
    size_t pos{0};
    if (str[pos] == '-' || str[pos] == '+')
        isNegative = str[pos++] == '-';
    for (; pos < str.size() && isdigit(str[pos]); ++pos)
        res = res * 10 + (str[pos] - '0');
    if (pos < str.size() && str[pos] == '.')
        ++pos;
    for ( T frac{ static_cast<T>(0.1) };
          pos < str.size() && isdigit(str[pos]);
          ++pos, frac /= 10 )
        res += (str[pos] - '0') * frac;
    if (pos != str.size())
        throw std::invalid_argument("str contained nondigits");
    return isNegative ? -res : res;
}

template <typename T>
T sqrt(T num, T tol = static_cast<T>(1e-6)) {
    if (num < 0)
        throw std::invalid_argument("Negative input");
    T guess{}, newGuess{num};
    while (abs(newGuess - guess) > tol) {
        guess = newGuess;
        newGuess = (guess + num / guess) / static_cast<T>(2);
    }
    return newGuess;
}

int main() {
    std::string inp{};
    std::cout << "Enter a number: ";
    while (std::getline(std::cin >> std::ws, inp)) {
        try {
            auto res{ sqrt(customStod<long double>(inp)) };
            std::cout << "The square root of " << inp << " is " << std::setprecision(20) << res << '\n';
            break;
        } catch (const std::invalid_argument& exc) {
            std::cerr << "Error: " << exc.what() << "\n" "try again: ";
        }
    }
    return EXIT_SUCCESS;
}
