#include <cstdlib>
#include <array>
#include <string_view>
#include <string>
#include <algorithm>
#include <iostream>

int main() {
    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };
    std::cout << "search for: ";
    std::string search{};
    std::cin >> search;
    auto found{std::find_if(arr.begin(), arr.end(),
                [search](std::string_view str) {
                    return str.find(search) != std::string_view::npos;
                }
            )};
    if (found == arr.end())
        std::cout << "Not found";
    else
        std::cout << "Fond " << *found << '\n';
    return EXIT_SUCCESS;
}
