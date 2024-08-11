#include <cstdlib>
#include <ios>
#include <iostream>

template <typename T, typename U>
class Pair {
    T first_{};
    U second_{};
public:
    explicit Pair() = default;
    explicit Pair(const T& first, const U& second)
        : first_{first}, second_{second} {}
    bool isEqual(const Pair<T, U>& other) const;
};

template <typename T, typename U>
bool Pair<T, U>::isEqual(const Pair<T, U>& other) const {
    return first_ == other.first_ && second_ == other.second_;
}

int main() {
    Pair p1{1.f, 2};
    std::cout << std::boolalpha
        << p1.isEqual(Pair{1.f, 2}) << '\n';
    return EXIT_SUCCESS;
}
