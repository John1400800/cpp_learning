/* with switch statements,
 * the statements after labels
 * are all scoped to the switch block.
 * No implicit blocks are created.      */

#include <cstdlib>
#include <iostream>

constexpr bool isVowel(char c) {
    switch (c) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return true;
        default:
            return false;
    }
}

int main() {
    std::cout << std::boolalpha << isVowel('t') << '\n';
    return EXIT_SUCCESS;
}
