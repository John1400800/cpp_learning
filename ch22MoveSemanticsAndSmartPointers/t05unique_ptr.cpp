#include <cstdlib>
#include <memory>       // for std::unique_ptr
#include <utility>      // for std::move
#include <iostream>

// Favor std::array, std::vector, or std::string over a smart pointer managing
// a fixed array, dynamic array, or C-style string.

struct Resource {
    Resource() {
        std::cout << "Resource acquired\n";
    }
    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
};

int main() {
    std::unique_ptr<Resource> res1{ new Resource{} };
    std::unique_ptr<Resource> res2{};
    std::cout << "res1 is " << (res1 ? " not null\n" : " null\n");
    std::cout << "res2 is " << (res2 ? " not null\n" : " null\n");
    res2 = std::move(res1);
    std::cout << "Ownership transferred\n";
    std::cout << "res1 is " << (res1 ? " not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? " not null\n" : "null\n");
    return EXIT_SUCCESS;
}
