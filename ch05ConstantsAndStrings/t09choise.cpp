#include <cstdint>
#include <cstdlib>
#include <string>
#include <iostream>

// Warning
// Do not initialize a std::string_view with a std::string literal, as this will leave the std::string_view dangling.
// It is okay to initialize a std::string_view with a C-style string literal or a std::string_view literal.
// It’s also okay to initialize a std::string_view with a C-style string object,
// a std::string object, or a std::string_view object, as long as that string object outlives the view

int main() {
    using namespace std::string_view_literals;
    std::cout << "Pick 1 or 2: "sv;
    uint_fast16_t choise{};
    std::cin >> choise;

    std::cout << "Now enter your name: "sv;
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Hello, "sv << name << ", you picked "sv << choise << '\n';
    return EXIT_SUCCESS;
}
