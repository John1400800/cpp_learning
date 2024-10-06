#include "utils.h"
#include "auto_ptr.h"
#include "elem.h"
#include <utility>

template <typename T>
void swap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template <typename T>
void selSort(T* begin, T* end, std::function<bool(const T&, const T&)> comp) {
    for (T* i = begin; i != end; ++i) {
        T* minElem = i;
        for (T* j = i + 1; j != end; ++j) {
            if (comp(*j, *minElem)) {
                minElem = j;
            }
        }
        if (minElem != i) {
            swap(*i, *minElem);
        }
    }
}

// Явная инстанциация selSort для Auto_ptr<Elem<uint32_t>>
template void selSort(Auto_ptr<Elem<uint32_t>>*, Auto_ptr<Elem<uint32_t>>*, 
                      std::function<bool(const Auto_ptr<Elem<uint32_t>>&, const Auto_ptr<Elem<uint32_t>>&)>);
