#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <iostream>

template <typename T>
class Array {
    static inline size_t idCntr_{0}; // Счетчик для идентификаторов
    T *array_{};
    size_t length_{};
    const size_t id_; // Уникальный идентификатор для каждого объекта
public:
    Array(size_t length=1) : id_{idCntr_++} { // Присвоение id при инициализации
        assert(length > 0);
        std::cout << "Constructing Array " << id_ << '\n';
        array_ = new T[length_=static_cast<size_t>(length)];
    }

    ~Array() {
        std::cout << "Destruction Array " << id_ << '\n';
        delete[] array_;
    }

    void setValue(size_t index, T value) {
        array_[index] = value;
    }

    const T& getValue(size_t index) const {
        return array_[index];
    }

    size_t length() const {
        return length_;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;
};

// Инициализация статического члена
// template <typename T>
// size_t Array<T>::idCntr_{1}; // Начинаем с 1

int main() {
    Array<uint32_t> arr{8};
    for (size_t i{0}; i<arr.length(); ++i)
        arr.setValue(i, i+1);
    std::cout << "The value of elem 5 is " << arr.getValue(5) << "\n";

    // Создаем массив указателей на Array<size_t>
    Array<size_t>** pArrs = new Array<size_t>*[2];
    pArrs[0] = new Array<size_t>(5); // id будет 2
    pArrs[1] = new Array<size_t>(5); // id будет 3

    // Убедимся, что деструкторы вызываются
    delete pArrs[0];
    delete pArrs[1];
    delete[] pArrs; // Удаляем массив указателей

    return EXIT_SUCCESS;
}
