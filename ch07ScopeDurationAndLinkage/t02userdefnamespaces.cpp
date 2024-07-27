#include <cstdlib>
#include <cstdint>
#include <iostream>

namespace Foo {
    int32_t doSomething(int32_t x, int32_t y) {
        return x+y;
    }
}

namespace Goo {
    int32_t doSomething(int32_t x, int32_t y) {
        return x-y;
    }
}

int main() {
    std::cout << Foo::doSomething(1, 2) << '\n';// Foo::doSomething(1, 2)
    return EXIT_SUCCESS;
}
