#include <cstdlib>
#include <cstdint>
#include <cstdarg>
#include <array>
#include <iostream>

double findAverage(const char *decoder, ...) {
    va_list list;
    va_start(list, decoder);
    double sum{ 0 };
    size_t i{0};
    for (; decoder[i]!='\0'; ++i)
        switch (decoder[i]) {
        case 'u':
            sum += va_arg(list, uint32_t);
            break;
        case 'd':
            sum += va_arg(list, double);
            break;
        }
    va_end(list);
    return sum / static_cast<double>(i);
}

template <size_t N>
double normalFindAverage(const std::array<double, N>& arr) { // better then ellision
    double sum{0};
    size_t cnt{0};
    for (; cnt < N; ++cnt)
        sum += arr[cnt];
    return sum / static_cast<double>(cnt);
}

int main() {
    std::array<double, 6> arr{1, 2, 0.5, 2, 2.5, 1};
    std::cout << findAverage("uududu", 1, 2, 0.5, 2, 2.5, 1) << '\n'
       << normalFindAverage(arr) << '\n'; // better
    return EXIT_SUCCESS;
}
