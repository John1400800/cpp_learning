#include <cstdlib>
#include <cstdint>
#include <array>
#include <string_view>
#include <algorithm>
#include <iostream>


struct Car {
    std::string_view make{};
    std::string_view model{};
};

int main() {
    std::array<Car, 3> cars{{
        { "Volkswagen", "Golf"          },
        { "Toyota",     "Corolla"       },
        { "Honda",      "Civic"         }
    }};
    size_t comparisons{0};
    std::sort(cars.begin(), cars.end(),
            // To capture all used variables by value, use a capture value of `=`.
            // To capture all used variables by reference, use a capture value of `&`.
            [&comparisons](const auto& a, const auto& b) {
            ++comparisons;
            return a.make < b.make;
            });
    std::cout << "Comparisons: " << comparisons << '\n';
    for (const auto& car : cars)
        std::cout << car.make << ' ' << car.model << '\n';
    return EXIT_SUCCESS;
}
