#include <cstdlib>
#include <cstdint>
#include <iostream>

template <typename T>
class Array {
    size_t length_{};
    T *data_{};
public:
    Array(size_t length);
    Array(std::initializer_list<T> iniList);

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    Array(Array&& arr) noexcept;
    Array& operator=(Array&& arr) noexcept;

    ~Array();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;
    const T *begin() const;
    const T *end() const;
};

template <typename T>
Array<T>::Array(size_t length)
    : length_{ length }
    , data_{ new T[length_]{} }
{ }

template <typename T>
Array<T>::Array(std::initializer_list<T> iniList)
    : Array(iniList.size())
{
    size_t i{0};
    for (auto& item : iniList) {
        data_[i++] = item;
    }
}

template <typename T>
Array<T>::Array(Array&& arr) noexcept
    : length_{arr.length_}, data_{arr.data_}
{
    arr.data_ = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& arr) noexcept {
    if (this != &arr)
        return *this;
    length_ = arr.length_;
    data_ = arr.data_;
    arr.data_ = nullptr;
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data_;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    return data_[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    return data_[index];
}

template <typename T>
size_t Array<T>::size() const {
    return length_;
}

template <typename T>
const T *Array<T>::begin() const {
    return data_;
}

template <typename T>
const T *Array<T>::end() const {
    return data_ + length_;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    bool isFirst{ true };
    for (const T& item : arr) {
        out << (!isFirst? ", " : "") << item;
        isFirst = false;
    }
    return out;
}

int main() {
    Array arr{1, 2, 3};
    std::cout << arr << '\n';
    return EXIT_SUCCESS;
}
