#include <cstdlib>
#include <cstdint>
#include <iostream>

template <typename T>
class Storage {
    T m_value{};
public:
    Storage(T value)
        : m_value{ value }
    { }

    void print() const {
        std::cout << m_value << '\n';
    }
};

template <typename T>
class Storage<T*> {
    T *m_value{};
public:
    Storage(T *value)
        : m_value{ value }
    { }

    void print() const {
        std::cout << *m_value << '\n';
    }
};

int main() {
    Storage s{ new double{1.5} };
    s.print();
    return EXIT_SUCCESS;
}

