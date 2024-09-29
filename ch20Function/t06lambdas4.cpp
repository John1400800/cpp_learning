#include <cstdlib>
#include <array>
#include <string_view>
#include <algorithm>
#include <iostream>

int main() {
    constexpr std::array months{
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    constexpr auto numFiveLetterMonth{ std::count_if(months.begin(), months.end(),
                                                     [](std::string_view str) {
                                                        return str.length() == 5;
                                                     }) };
    std::cout << "There are " << numFiveLetterMonth << " months with 5 letters\n";
    return EXIT_SUCCESS;
}
