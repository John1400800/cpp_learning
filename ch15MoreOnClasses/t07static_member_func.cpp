#include <cstdint>
#include <cstdlib>
#include <iostream>

class Something {
    static uint32_t nextId_;
    uint32_t id_;
public:
    Something();
    uint32_t getId() const;
    static uint32_t getNextId();
};

uint32_t Something::nextId_{ 0 };
Something::Something() :id_{ Something::nextId_++ } {
}

uint32_t Something::getId() const {
    return id_;
}

uint32_t Something::getNextId() {
    return nextId_;
}

int main() {
    for (size_t count{0}; count < 10; ++count) {
        std::cout << "the next if is: " << Something::getNextId() << '\n';
        Something{};
    }
    return EXIT_SUCCESS;
}
