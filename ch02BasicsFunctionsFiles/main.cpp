#include <c++/13.2/iostream>
#include <c++/13.2/cstdlib>

int getInteger();

int main() {
    int x{ getInteger() };
    int y{ getInteger() };
    std::cout << x << " + " << y << " = " << x+y << '\n';
    return EXIT_SUCCESS;
}
