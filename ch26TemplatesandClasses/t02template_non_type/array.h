// array.h
#ifndef STATIC_ARRAY
#define STATIC_ARRAY

#include <cstddef>
#include <ostream>

template <typename T, size_t N>
class StaticArray {
    T array_[N];
public:
    constexpr size_t size() const {
        return N;
    }
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
};

template <typename T, size_t N>
std::ostream&
operator<<(std::ostream& out, StaticArray<T, N> arr);
#endif // STATIC_ARRAY
