#include <cstdlib>
#include "array.h"

int main() {
    Array intArr{1, 2, 3};
    Array doubleArr{1.1, 2.2, 3.3};
    std::cout << intArr << '\n'
              << doubleArr << '\n';
    return EXIT_SUCCESS;
}
