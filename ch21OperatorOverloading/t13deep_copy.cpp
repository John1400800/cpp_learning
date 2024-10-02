#include <cstdlib>
#include <cstddef>
#include <cassert>
#include <cstring>
#include <iostream>

class MyStrnig {
    char        *data_{};
    size_t      length_{};

    void deepCopy(const MyStrnig&);
public:
    MyStrnig(const char *source="");
    MyStrnig(const MyStrnig&);
    ~MyStrnig();
    MyStrnig& operator=(const MyStrnig& source);
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

MyStrnig::MyStrnig(const MyStrnig& source) {
    deepCopy(source);
}

MyStrnig& MyStrnig::operator=(const MyStrnig& source) {
    if (this != &source)
        deepCopy(source);
    return *this;

}

MyStrnig::~MyStrnig() {
    delete[] data_;
}

void MyStrnig::deepCopy(const MyStrnig& source) {
    delete[] data_;
    length_ = source.length_;
    if (source.data_) {
        data_ = new char[length_];
        for (size_t i{0}; i<length_; ++i)
            data_[i] = source.data_[i];
    } else
        data_ = nullptr;
}

std::ostream& operator<<(std::ostream& out, const MyStrnig& str) {
    return out << str.data_;
}
