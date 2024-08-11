#include <cstdint>
#include <cstdlib>
#include <iostream>

template <typename T>
class Value {
    T value_{};
public:
    Value(const T& value);
    bool isEqualToMember(const Value<T>& other) const;
    template <typename U>
    friend bool isEqualToNoMember(const Value<U>& first, const Value<U>& second);
};

template <typename T>
Value<T>::Value(const T& value)
    : value_{value} {}

template <typename T>
bool Value<T>::isEqualToMember(const Value<T>& other) const {
    return value_ == other.value_;
}

template <typename T>
bool isEqualToNoMember(const Value<T>& first, const Value<T>& second) {
    return first.value_ == second.value_;
}

int main() {
    Value v1{1};
    Value v2{1};
    std::cout << std::boolalpha << "v1 is equal v2: "<< v1.isEqualToMember(v2) << "\nv1 is equal v1: " << isEqualToNoMember(v1, v2) << '\n';
    return EXIT_SUCCESS;
}
