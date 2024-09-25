#include <cstdlib>
#include <string_view>
#include <array>
#include <algorithm>
#include <iostream>

bool containsNut(std::string_view str);

int main() {
    std::array arr{ "apple", "banana", "walnut", "lemon", "peanut" };
    std::cout << "Counted "
        << std::count_if(arr.begin(), arr.end(), containsNut) << " nut(s)\n";
    return EXIT_SUCCESS;
}

bool containsNut(std::string_view str) {
    return str.find("nut") != std::string_view::npos;
}
