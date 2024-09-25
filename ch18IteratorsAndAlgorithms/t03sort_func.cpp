#include <cstdlib>
#include <cstdint>
#include <chrono>
#include <iterator>
#include <functional>
#include <iostream>

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
}

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
std::ostream& operator<<(std::ostream& out, const T (&arr)[N]) {
    for (size_t i=0; i < N; ++i)
        std::cout << (i!=0?", ":"") << arr[i];
    return out;
}

int main() {
    uint32_t arr[]{ 2, 1, 9, 4, 5 };
    Timer timer;
    std::cout << timer.elapsed() << '\n';
    selSort(std::begin(arr), std::end(arr), smaller<uint32_t>);
    std::cout << timer.elapsed() << arr << '\n';
    return EXIT_SUCCESS;
}
