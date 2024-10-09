#include <cstdlib>
#include <memory>
#include <iostream>

struct Resource {
    std::shared_ptr<Resource> ptr_{};
    Resource() {
        std::cout << "Resource acquired\n";
    }
    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
};

int main() {
    auto ptr1{ std::make_shared<Resource>() };
    ptr1->ptr_ = ptr1; // ptr_ is now sharing the Resource that contains it
    return EXIT_SUCCESS;
}
