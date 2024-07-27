#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>

bool isPrime(uint16_t num) {
    if (num<2)
        return false;
    else if (num==2)
        return true;
    else if (num%2==0)
        return false;
    for (uint16_t r{3}; r*r<=num; r+=2)
        if (num%r==0)
            return false;
    return true;
}

int main() {
    for (uint16_t number{2}, numPrinted{0}; number<1000; ++number)
        if (isPrime(number)) {
            std::cout<<std::setw(3)<<number<<(numPrinted%12==11?'\n':' ');
            ++numPrinted;
        }
    return EXIT_SUCCESS;
}
