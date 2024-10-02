#include <cstdlib>
#include <string_view>
#include <iostream>

struct Stupid {
    void operator[](const char*) const;
};

int main() {
    Stupid{}["Hello world!"];
    return EXIT_SUCCESS;
}

void Stupid::operator[](const char* str) const {
    std::cout << str << '\n';
}
