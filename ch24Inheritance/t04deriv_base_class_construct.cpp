#include <cstdlib>
#include <cstdint>
#include <iostream>

class Base {
    size_t id_{};
public:
    Base(size_t id=0)
        : id_{ id }
    { }

    size_t getId() const {
        return id_;
    }
};

class Derived : public Base {
    double cost_{};
public:
    Derived(double cost=0.0, size_t id=0)
        : Base(id), cost_{ cost }
    { }

    double getCost() const {
        return cost_;
    }
};

int main() {
    Derived derived{ 1.3, 5 };
    std::cout <<   "Id: " <<   derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';
    return EXIT_SUCCESS;
}
