#include <cstdlib>
#include <cstdint>
#include <functional>
#include <iostream>

void repeat1(size_t, const std::function<void(size_t)>&);

// use in heaser or in file where used
void repeat2(size_t repetitions, const auto& fn) {
    for (size_t i{0}; i<repetitions; ++i)
        fn(i);
}

int main() {
    auto printFn{
        [](size_t num) -> void {
            std::cout << (num!=0?", ":"") << num;
        }
    };
    repeat2(4, printFn);
    std::cout << '\n';
    repeat1(4, printFn);
    std::cout << '\n';
    return EXIT_SUCCESS;
}

// use a `std::function` parameter if lambda with no captures
// and define func in module
void repeat1(size_t repetitions, const std::function<void(size_t)>& fn) {
    for (size_t i{0}; i<repetitions; ++i)
        fn(i);
}

