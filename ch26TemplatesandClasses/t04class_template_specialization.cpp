#include <cstdlib>
#include <cstdint>
#include <iostream>

template <typename T>
class Storage8 {
    T array[8];
public:
    void set(size_t index, const T &value) {
        array[index] = value;
    }

    const T& get(size_t index) const {
        return array[index];
    }
};

template <>
class Storage8<bool> {
    uint8_t array;
public:
    void set(size_t index, bool value) {
        array = uint8_t(array & ~(1u<<index)) | (value<<index);
    }

    bool get(size_t index) const {
        return array & 1u<<index;
    }
};

int main() {
    Storage8<uint32_t> intStorage;
    Storage8<bool    > boolStorage;
    for (size_t count{0}; count < 8; ++count) {
        intStorage.set(count, uint32_t(count));
        boolStorage.set(count, count % 2==0);
    }
    for (size_t i{0}; i < 8; ++i) {
        std::cout << intStorage.get(i) << '\t'
            << std::boolalpha << boolStorage.get(i) << '\n';
    }
    return EXIT_SUCCESS;
}
