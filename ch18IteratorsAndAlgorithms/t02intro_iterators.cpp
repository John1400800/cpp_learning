#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>

int main() {
    std::vector<uint32_t> vec{1, 2, 3, 4, 5};
    auto it{vec.begin()};
    ++it;
    it = vec.erase(it);
    for (bool isFirst{true}; it!=vec.end(); ++it) {
        std::cout << (!isFirst?", ":"") << *it;
        isFirst = false;
    }
    std::cout << '\n';
    return EXIT_SUCCESS;
}
