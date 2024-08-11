#ifndef RANDGEN_H
#define RANDGEN_H
#include <chrono>
#include <random>

class Randgen {
    static std::mt19937 state;
    static std::mt19937 helpInitMt();
public:
    template <typename T>
    static T get(const T& min, const T& max) {
        return std::uniform_int_distribution<T>( min, max )(state);
    }
};

#endif//RANDGEN_H
