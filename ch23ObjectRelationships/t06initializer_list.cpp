#include <cstdlib>      // for EXIT_SUCCESS
#include <cstdint>      // for int32_t
#include <cassert>      // for assert
#include <initializer_list> // for std::initializer_list
#include <iostream>     // for cout, cin, endl

template <typename T>
class Array {
    T       *data_{};
    size_t length_{};
public:
    Array(size_t length=0)
        : data_{ length>0? new T[length] : nullptr }, length_{ length }
    { }

    // copies as in string_view are easier than reference
    Array(std::initializer_list<T> list)
        : Array( list.size() ) // uses direct initialization `Type obj(...)'
    {
        size_t index{0};
        for (const auto& item : list)
            data_[index++] = item;
    }

    ~Array() {
        delete[] data_;
    }

    Array(const Array& arr)
        : Array(arr.length_)
    {
        for (size_t i{0}; i<length_; ++i)
            data_[i] = arr[i];
    }

    Array& operator=(const Array& arr) {
        if (&arr == this)
            return *this;
        reallocate(arr.length_);
        for (size_t i{0}; i<length_; ++i)
            data_[i] = arr[i];
        return *this;
    }

    Array& operator=(std::initializer_list<T> list) {
        reallocate(list.size());
        size_t index{0};
        for (const auto& item : list)
            data_[index++] = item;
        return *this;
    }

    T& operator[](size_t index) {
        assert(index < length_);
        return data_[index];
    }

    const T& operator[](size_t index) const {
        assert(index < length_);
        return data_[index];
    }

    size_t getLength() const {
        return length_;
    }

    void erase() {
        delete[] data_;
        data_   = nullptr;
        length_ = 0;
    }

    void reallocate(size_t newLength) {
        erase();
        if (newLength == 0)
            return ;
        data_   = new T[newLength];
        length_ = newLength;
    }

    void resize(size_t newLength) {
        if (newLength == length_)
            return ;
        if (newLength == 0) {
            erase();
            return ;
        }
        T *data{ new T[newLength] };
        for (size_t i{0}; i < (newLength < length_? newLength : length_); ++i)
            data[i] = data_[i];
        delete[] data_;
        data_ = data;
        length_ = newLength;
    }

    void insertBefore(T value, size_t index) {
        assert(index <= length_);
        T *data{ new T[length_+1] };
        for (size_t i{0}; i<length_+1; ++i)
            if (i == index)
                data[i] = value;
            else if (i < index)
                data[i] = data_[i];
            else if (i > index)
                data[i] = data_[i-1];
        delete[] data_;
        data_ = data;
        ++length_;
    }

    void remove(size_t index) {
        assert(index < length_);
        if (length_ == 1) {
            erase();
            return ;
        }
        T *data{ new T[length_-1]};
        for (size_t i{0}; i<length_-1; ++i)
            if (i<index)
                data[i] = data_[i];
            else
                data[i] = data_[i+1];
        delete[] data_;
        data_ = data;
        --length_;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    if (arr.getLength() == 0)
        return out << "Array is empty!";
    for (size_t i{0}; i<arr.getLength(); ++i)
        out << (i>0? ", ":"{ ") << arr[i];
    return out << " }";
}

int main() {
    Array<uint32_t> arr{ 5, 4, 3, 2, 1 };
    std::cout << arr << '\n';
    arr = { 1, 3, 5, 7, 9, 11 };
    std::cout << arr << '\n';
    return EXIT_SUCCESS;
}
