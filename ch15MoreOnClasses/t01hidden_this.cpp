#include <cstdlib>
#include <cstdint>
#include <iostream>

class Calc {
    int32_t currVal{0};
public:
    Calc(int32_t initVal=0) : currVal{ initVal } {
        std::cout << "init Calc"<<this<<"(" << currVal << ")\n";
    }
    Calc(Calc& copied) : currVal{copied.currVal} {
        std::cout << "copy Calc(" << copied.currVal << ")\n";
    }
    Calc& add(int32_t val) {
        currVal += val;
        return *this;
    }
    Calc& sub(int32_t val) {
        currVal -= val;
        return *this;
    }
    Calc& mult(int32_t val) {
        currVal *= val;
        return *this;
    }
    int32_t getCurr() const {
        return currVal;
    }
    Calc& reset() {
        *this = {};
        return *this;
    }
};

int main() {
    Calc calc;
    std::cout << calc.add(5).sub(3).mult(4).getCurr() << '\n';
    std::cout << calc.reset().getCurr() << '\n';
    return EXIT_SUCCESS;
}
