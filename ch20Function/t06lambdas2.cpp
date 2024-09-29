#include <cstdlib>
#include <array>
#include <string_view>
#include <algorithm>
#include <iostream>

int main() {
    std::array<std::string_view, 6> arr{ "apple", "banana", "walnut", "lemon" };
    auto found{ std::find_if(arr.begin(), arr.end(),
            [](std::string_view str) -> bool {
                return str.find("nut") != std::string_view::npos;
            }) };
    if (found == arr.end())
        std::cout << "No nuts";
    else
        std::cout << "Found " << *found << '\n';
    return EXIT_SUCCESS;
}
