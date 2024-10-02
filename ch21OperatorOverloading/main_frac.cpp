#include <cstdlib>
#include <iostream>
#include "frac.hpp"

int main() {
    std::cout << "Enter fraction 1: ";
    Fraction f1{};
    std::cin >> f1;
    std::cout << "Enter fraction 2: ";
    Fraction f2{};
    std::cin >> f2;
    std::cout
        << f1 << " +  " << f2 << " == "                <<  f1 +  f2  << '\n'
        << f1 << " -  " << f2 << " == "                <<  f1 -  f2  << '\n'
        << f1 << " *  " << f2 << " == "                <<  f1 *  f2  << '\n'
        << f1 << " /  " << f2 << " == "                <<  f1 /  f2  << '\n'
        << f1 << " == " << f2 << std::boolalpha << ' ' << (f1 == f2) << '\n'
        << f1 << " != " << f2                   << ' ' << (f1 != f2) << '\n'
        << f1 << " >  " << f2                   << ' ' << (f1 >  f2) << '\n'
        << f1 << " <  " << f2                   << ' ' << (f1 <  f2) << '\n'
        << f1 << " >= " << f2                   << ' ' << (f1 >= f2) << '\n'
        << f1 << " <= " << f2                   << ' ' << (f1 <= f2) << '\n'
        << "++(" << f1 << ") == " << ++f1 << '\n'
        << "--(" << f1 << ") == " << --f1 << '\n'
        << "(" << f1 << ")++ == " << f1++ << ", f == " << f1 << '\n'
        << "(" << f1 << ")-- == " << f1-- << ", f == " << f1 << '\n'
        << "int32_t(" << f1 << ") == " << static_cast<int32_t>(f1) << ", double("
        << f1 << ") == " << double(f1) << '\n';
    return EXIT_SUCCESS;
}
