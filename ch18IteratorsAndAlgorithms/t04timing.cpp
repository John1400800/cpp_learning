#include <cstdlib>      // for program exit code
#include <cstdint>      // for _t
#include <chrono>       // for std::chrono
#include <functional>   // for std::function
#include <algorithm>    // for std::sort
#include <numeric>      // for std::iota
#include <iostream>     // for cout

class Timer {
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;
    std::chrono::time_point<Clock> start_{ Clock::now() };
public:
    void reset() {
        start_ = Clock::now();
    }
    double elapsed() const {
        return std::chrono::duration_cast<Second>(Clock::now() - start_).count();
    }
};

template <typename T>
void swap(T& first, T& second) {
    T temp{first};
    first = second;
    second = temp;
}

template <typename T>
void selSort(T *begin, T *end, std::function<bool(const T&, const T&)> compare) {
    for(T *startPtr{begin}; startPtr != end-1; ++startPtr) {
        T *smallestPtr{startPtr};
        for(T *currPtr{startPtr+1}; currPtr != end; ++currPtr)
            if (compare(*currPtr, *smallestPtr))
                smallestPtr = currPtr;
        swap(*startPtr, *smallestPtr);
    }
}

template <typename T>
bool smaller(const T& first, const T& second) {
    return first < second;
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& arr) {
    for (size_t i=0; i < N; ++i)
        std::cout << (i!=0?", ":"") << arr[i];
    return out;
}

namespace {
    constexpr size_t g_arrayElements{1000};
};

int main() {
    std::array<uint32_t, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1);
    Timer timer;
    // selSort(std::begin(array), std::end(array), smaller<uint32_t>);
    std::sort(array.begin(), array.end(), smaller<uint32_t>);
    std::cout << "Time taken: " << timer.elapsed() << " seconds\n";
        // << array << '\n';
    return EXIT_SUCCESS;
}
