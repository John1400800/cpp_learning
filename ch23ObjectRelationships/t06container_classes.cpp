#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <iostream>

template <typename T>
class Array {
    T       *data_{};
    size_t length_{};
public:
    Array(size_t length=0)
        : data_{ length>0? new T[length] : nullptr }, length_{ length }
    {
        // assert(length >= 0);
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
    for (size_t i{0}; i<arr.getLength(); ++i)
        out << (i>0? ", ":"{ ") << arr[i];
    return out << " }";
}

int main() {
    Array<int32_t> array(10);
    for (size_t i{ 0 }; i<10; ++i)
        array[i] = static_cast<int32_t>(i+1);

    array.resize(8);

    array.insertBefore(20, 5);

    array.remove(3);

    array.insertBefore(30, array.getLength());
    array.insertBefore(40, 0);
    {
        Array b{ array };
        b = array;
        b = b;
        array = array;
    }
    for (size_t i{0}; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';
    std::cout << '\n';

#if 0
    Array<uint32_t> arr(4);
    for (size_t i{0}; i<arr.getLength(); ++i)
        arr[i] = static_cast<uint32_t>(i);
    arr.remove(2);
    std::cout << arr << '\n';
#endif
    return EXIT_SUCCESS;
}
