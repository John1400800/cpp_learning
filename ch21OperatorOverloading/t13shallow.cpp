#include <cstdlib>
#include <cstddef>
#include <cassert>
#include <cstring>
#include <iostream>

class MyStrnig {
    char        *data_{};
    size_t      length_{};
public:
    MyStrnig(const char *source="");
    ~MyStrnig();

    friend std::ostream& operator<<(std::ostream& out, const MyStrnig& str);
};

int main() {
    MyStrnig str{"Hello world"};
    {
        MyStrnig copy{ str };
    }
    std::cout << str << '\n';
    return EXIT_SUCCESS;
}


MyStrnig::MyStrnig(const char *source) {
    assert(source && "source is nullptr");
    length_ = strlen(source) + 1;
    data_ = new char[length_];
    for (size_t i{0}; i < length_; ++i)
        data_[i] = source[i];
}

MyStrnig::~MyStrnig() {
    delete[] data_;
}

std::ostream& operator<<(std::ostream& out, const MyStrnig& str) {
    return std::cout << str.data_;
}
