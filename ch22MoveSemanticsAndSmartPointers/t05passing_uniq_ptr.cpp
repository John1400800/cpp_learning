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

std::ostream& operator<<(std::ostream& out, const Resource&) {
    return out << "I am a resource";
}

void takeOwnership(std::unique_ptr<Resource> res) {
    if (res)
        std::cout << "Resource by ownership: " << *res << "\n"
            "in function by ownership - ";
}

void useResource(const Resource *res) {
    if (res)
        std::cout << "Resource using a regular "
            "pointer via .unique_ptr::get(): " << *res << '\n';
    else
        std::cout << "in function by smplPtr: No resource\n";
}

int main() {
    auto ptr{ std::make_unique<Resource>() };
    useResource(ptr.get());
    takeOwnership(std::move(ptr));
    // Ownership of the Resource was transferred to takeOwnership(), so the
    // Resource was destroyed at the end of takeOwnership()
    useResource(ptr.get());
    return EXIT_SUCCESS;
}
