#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>


uint32_t fibonacci(size_t count) {
    static std::vector<uint32_t> results{ 0, 1 };
    if (count < std::size(results))
        return results[count];
    results.push_back(fibonacci(count-1)+fibonacci(count-2));
    return results[count];
}

int main() {
    std::cout << fibonacci(6) << '\n';
    return EXIT_SUCCESS;
}
