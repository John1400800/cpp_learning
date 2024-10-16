#include <cstdlib>
#include <cstdint>
#include <string_view>
#include <iostream>

class Base {
protected:
    virtual std::ostream& print(std::ostream& out) const {
        return out << "Base";
    }
public:
    friend std::ostream& operator<<(std::ostream& out, const Base& b) {
        return b.print(out);
    }

    virtual ~Base() = default;
};

class Derived: public Base {
protected:
    std::ostream& print(std::ostream& out) const override {
        return out << "Derived";
    }
};

int main() {
    Base *bPtr{ new Derived{} };
    std::cout << *bPtr << '\n';
    delete bPtr;
    return EXIT_SUCCESS;
}
