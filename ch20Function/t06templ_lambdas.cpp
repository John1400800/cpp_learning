#include <cstdlib>
#include <iostream>

int main() {
    auto print{
        [](auto value) {
            static size_t callCnt{0};
            std::cout << callCnt++ << ": " << value << '\n';
        }
    };
    print("hello");
    print("world");
    print(9);
    print(10);
    print("ding dong");
    return EXIT_SUCCESS;
}
