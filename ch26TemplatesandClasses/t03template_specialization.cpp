#include <cstdlib>
#include <iostream>

template <typename T>
void print(std::ostream &out, const T &value) {
    out << value << '\n';
}

template <>
void print<double>(std::ostream &out, const double &value) {
    out << std::scientific << value << '\n';
}

int main() {
    print(std::cout, 1.2f);
    print(std::cout, 1.2);
    return EXIT_SUCCESS;
}
