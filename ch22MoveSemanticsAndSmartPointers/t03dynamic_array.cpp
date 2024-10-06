#include <cstdlib>
#include <cstdint>
#include <chrono>
#include <iostream>


class Timer {
private:
    using Clock = std::chrono::high_resolution_clock;
    using Second = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<Clock> m_beg { Clock::now() };
public:
    void reset() {
        m_beg = Clock::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

template <typename T>
class DynamicArray {
    T* array_{};
    size_t length_{};
public:
    DynamicArray(size_t length)
        : array_{new T[length]}, length_{length}
    { }

    ~DynamicArray() {
        delete[] array_;
    }

    DynamicArray(const DynamicArray& arr) = delete;
    /* DynamicArray(const DynamicArray& arr) // Copy constructor
        : array_{ new T[arr.length_] }, length_{ arr.length_ }
    {
        // Copy length elements from arr.array_ to array_
        // std::n_copy(arr.array_, length_, array_);
        for (size_t i{0}; i<length_; ++i)
            array_[i] = arr.array_[i];
    } */

    DynamicArray& operator=(const DynamicArray& arr) = delete;
    /* DynamicArray& operator=(const DynamicArray& arr) {
        if (this == &arr)
            return *this;
        delete[] array_;
        length_ = arr.length_;
        array_ = new T[length_];
        for (size_t i{0}; i<length_; ++i)
            array_[i] = arr.array_[i];
        return *this;
    } */

    DynamicArray(DynamicArray&& arr) noexcept
        : array_{arr.array_}, length_{arr.length_}
    {
        arr.length_ = 0;
        arr.array_ = nullptr;
    }

    DynamicArray& operator=(DynamicArray&& arr) noexcept {
        if (this == &arr)
            return *this;
        delete[] array_;
        length_ = arr.length_;
        array_ = arr.array_;
        arr.length_ = 0;
        arr.array_ = nullptr;
        return *this;
    }

    size_t length() const {
        return length_;
    }

    T& operator[](size_t index) {
        return array_[index];
    }

    const T& operator[](size_t index) const {
        return array_[index];
    }

    const T* begin() {
        return array_;
    }

    const T* end() {
        return array_ + length_;
    }
};

// Return a copy  off arr with all of the values doubled
DynamicArray<uint32_t> cloneArrayAndDouble(const DynamicArray<uint32_t>& arr) {
    DynamicArray<uint32_t> doubledArray{arr.length()};
    for (size_t i{0}; i<arr.length(); ++i)
        doubledArray[i] = arr[i]*2;
    return doubledArray;
}

int main() {
    Timer t;
    DynamicArray<uint32_t> arr{ 1'000'000 };
    for (size_t i{0}; i<arr.length(); ++i)
        arr[i] = static_cast<uint32_t>(i);
    arr = cloneArrayAndDouble(arr);
    std::cout << t.elapsed() << '\n';
    return EXIT_SUCCESS;
}
