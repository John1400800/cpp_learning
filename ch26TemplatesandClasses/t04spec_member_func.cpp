#include <cstdlib>
#include <cstdint>
#include <iostream>

template <typename T>
class Storage {
    T value{};
public:
    Storage(const T &value) : value{ value } {}

    template <typename U>
    friend class Storage;

    template <typename U>
    Storage(const Storage<U> &stor) 
        : value{ static_cast<T>(stor.value) } 
    { }

    void print(std::ostream &out) {
        out << value << '\n';
    }
};

template <>
void Storage<double>::print(std::ostream &out) {
    out << std::scientific << value << '\n';
}

int main() {
    Storage storFloat{ 0.5f };
    storFloat.print(std::cout);
    static_cast<Storage<double>>(storFloat).print(std::cout);
    return EXIT_SUCCESS;
}
