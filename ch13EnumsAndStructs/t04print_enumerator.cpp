#include <cstdlib>
#include <string_view>
#include <iostream>

enum Color {
    black,
    red,
    blue,
};
/* Reminder:
 * Because C-style string literals exist
 * for the entire program, it’s okay to
 * return a std::string_view that is viewing
 * a C-style string literal. When the std::string_view
 * is copied back to the caller,
 * the C-style string literal being viewed will still
 * exist. */
constexpr std::string_view getColorName(Color color) {
    switch (color) {
#define enum_eq(en) case (en): return #en
    enum_eq(black);
    enum_eq(red);
    enum_eq(blue);
#undef enum_eq
    default: return "???";
    }
}

int main() {
    constexpr Color shirt{ blue };
    std::cout << "You shirt is: " << getColorName(shirt) << '\n';
    return EXIT_SUCCESS;
}
