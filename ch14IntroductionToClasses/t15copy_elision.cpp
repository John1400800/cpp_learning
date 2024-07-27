
#include <cstdlib>
#include <iostream>

class Something {
    public:
        Something() = default;
        Something(const Something&) {
            std::cout << "Copy constructor called\n";
        }
};

Something rvo() {
    return Something{}; // calls Something() and copy constructor
}

Something nrvo() {
    Something s{}; // calls Something()
    return s;      // calls copy constructor
}

int main() {
    std::cout << "Initializing s1\n";
    Something s1 { rvo() }; // calls copy constructor
    std::cout << "Initializing s2\n";
    Something s2 { nrvo() }; // calls copy constructor
    return EXIT_SUCCESS;
}
