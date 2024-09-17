#include <cstdlib>
#include <cstdint>
#include <limits>
#include <array>
#include <iostream>

template <typename T, std::size_t N>
std::istream& operator>>(std::istream& in, std::array<T, N>& arr) {
    for (T& item : arr)
        while (!(in >> item)) {
            std::cout << "Invalid input, try again: ";
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    return in;
}

template <std::size_t N, std::size_t M>
std::istream& operator>>(std::istream& in, std::array<char[M], N>& arr) {
    for (auto& item : arr)
        in.getline(item, M);
    return in;
}

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& arr) {
    bool first = true;
    for (const T& item : arr) {
        out << (first? "" : ", ") << item;
        first = false;
    }
    std::cout << '\n';
    return out;
}

int main() {
    std::array<uint32_t, 2> arr;
    std::cin >> arr;
    std::cout << arr;
    return EXIT_SUCCESS;
}
