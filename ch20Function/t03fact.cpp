#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>

uint32_t fact(size_t count) {
    static std::vector<uint32_t> facts{1};
    if (count >= std::size(facts))
        facts.push_back(fact(count-1)*static_cast<uint32_t>(count));
    return facts[count];
}

int main() {
    std::cout << fact(5) << '\n';
    return EXIT_SUCCESS;
}
