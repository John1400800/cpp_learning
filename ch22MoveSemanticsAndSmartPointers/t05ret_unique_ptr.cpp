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

std::unique_ptr<Resource> createResource() {
    return std::make_unique<Resource>();
}

int main() {
    auto ptr{ createResource() };
    return EXIT_SUCCESS;
}
