#include <cstdlib>
#include <string_view>
#include <array>
#include <algorithm>
#include <iostream>

bool containsNut(std::string_view str);

int main() {
    std::array arr{ "apple", "banana", "walnut", "lemon" };
    auto found{std::find_if(arr.begin(), arr.end(), containsNut)};
    if (found == arr.end())
        std::cout << "No nuts\n";
    else
        std::cout << "Found " << *found << '\n';
    return EXIT_SUCCESS;
}

bool containsNut(std::string_view str) {
    return str.find("nut") != std::string_view::npos;
}
