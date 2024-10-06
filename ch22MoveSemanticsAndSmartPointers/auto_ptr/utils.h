// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <utility>
#include <functional>

template <typename T>
void swap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template <typename T, typename Compare>
void selSort(T* begin, T* end, Compare comp) {
    for (T* i = begin; i != end; ++i) {
        T* minElem = i;
        for (T* j = i + 1; j != end; ++j) {
            if (comp(*j, *minElem)) {
                minElem = j;
            }
        }
        if (minElem != i) {
            ::swap(*i, *minElem);
        }
    }
}

#endif // UTILS_H
