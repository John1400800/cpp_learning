#include <cstdlib>
#include <array>
#include <string_view>
#include <iostream>

namespace Color {
    enum Type {
        black,
        red,
        blue,
        max_colors
    };
    constexpr std::array<std::string_view, max_colors> name{
        "black",
        "red",
        "blue"
    };
    static_assert(std::size(name) == max_colors);
};

std::ostream& operator<<(std::ostream& out, Color::Type color) {
    return out << Color::name[color];
}

std::istream& operator>>(std::istream& in, Color::Type& color) {
    std::string input{};
    std::getline(in >> std::ws, input);
    for (std::size_t index{0}; index < Color::max_colors; ++index)
        if (input == Color::name[index]) {
            color = static_cast<Color::Type>(index);
            return in;
        }
    in.setstate(std::ios_base::failbit);
    return in;
}

int main() {
    std::cout << Color::black << '\n';
    return EXIT_SUCCESS;
}
