#include <cstdint>
#include <cstdlib>
#include <c++/13.2/cctype>
#include <iostream>

enum class Color : uint8_t {
    UNKNOWN=0,
    RED,
    GREEN,
    BLUE,
};

std::ostream& operator<<(std::ostream& os, const Color& color) {
    switch (color) {
    using enum Color;
    case RED:   os << "RED";     break;
    case GREEN: os << "GREEN";   break;
    case BLUE:  os << "BLUE";    break;
    case UNKNOWN: default:
                os << "UNKNOWN"; break;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Color& color) {
    std::string str;
    is >> str;
    for (char& c : str)
        c = static_cast<char>(std::toupper(c));
    using enum Color;
    if      (str == "RED")      color = RED;
    else if (str == "GREEN")    color = GREEN;
    else if (str == "BLUE")     color = BLUE;
    else                        color = UNKNOWN;
    return is;
}

int main() {
    Color color;
    std::cin >> color;
    std::cout << "Entered color: " << color << '\n';
    return EXIT_SUCCESS;
}
