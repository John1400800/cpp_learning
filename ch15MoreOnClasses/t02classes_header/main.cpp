#include "date.h"
#include <cstdint>
#include <cstdlib>

int main() {
    Date today{2024, 7, 3};
    print(today);
    return EXIT_SUCCESS;
}
