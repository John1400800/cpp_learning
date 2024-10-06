#ifndef UTILS_H
#define UTILS_H

#include <functional>

template <typename T>
void swap(T&, T&);

template <typename T>
void selSort(T*, T*, std::function<bool(const T&, const T&)>);

#endif // UTILS_H
