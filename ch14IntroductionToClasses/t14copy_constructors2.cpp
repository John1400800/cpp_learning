#include <cstdint>
#include <cstdlib>
#include <iostream>

class Something {
    uint32_t *data;
public:
    Something(uint32_t value) : data{new uint32_t(value)} {
        std::cout << "Constructor called\n";
    }
    Something(const Something& other) : data{new uint32_t(*other.data)} {
        std::cout << "Copy constructor called\n";
    }
    ~Something() {
        delete data;
        std::cout << "Destructor called\n";
    }
    void print() const {
        std::cout << "Value: " << *data << '\n';
    }
    friend void print(const Something& something);
};

void print(const Something& something) {
    something.print();
}

int main() {
    Something obj1{10};
    Something obj2{obj1};
    print(obj1);
    print(obj2);
    return EXIT_SUCCESS;
}
