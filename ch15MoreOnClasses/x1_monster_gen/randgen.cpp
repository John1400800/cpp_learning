#include "randgen.hpp"
#include <chrono>
#include <random>

std::mt19937 Randgen::state{ helpInitMt() };

std::mt19937 Randgen::helpInitMt() {
    std::random_device rd{};
    std::seed_seq seedSeq {
        static_cast<std::seed_seq::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count(), 
            rd(), rd(), rd(), rd(), rd(), rd(), rd()) };
    return std::mt19937{ seedSeq };
}

