#include <cstdint>
#include <cstring>
#include <iostream>

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& out, const T(&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        out << (i != 0 ? ", " : "") << arr[i];
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const char* str) {
    return out.write(
            str,
            static_cast<std::streamsize>(std::strlen(str)));
}

int main() {
    const uint32_t arr[]{1, 2, 3};
    std::cout << arr << '\n';
    std::cout << "hello" << '\n';
    return 0;
}
