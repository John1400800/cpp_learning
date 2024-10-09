#include <cstdlib>
#include <memory>
#include <iostream>

struct Resource {
    Resource() {
        std::cout << "Resource acquired\n";
    }
    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
};

int main() {
    // allocate a Resource object and have it owned by std::shared_ptr
    auto ptr1{ std::make_shared<Resource>() };
    {
        auto ptr2{ ptr1 };
        std::cout << "Killing one shared pointer\n";
    }
    std::cout << "Killing another shared pointer\n";
    return EXIT_SUCCESS;
}
