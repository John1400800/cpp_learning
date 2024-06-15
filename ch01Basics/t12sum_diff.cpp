#include <c++/13.2/iostream>

int main() {
    int num1{}, num2{};
    for (int& numref : {std::ref(num1), std::ref(num2)}) {
        std::cout << "Enter an num: ";
        std::cin >> numref;
    }
    std::cout << num1 << " + " << num2 << " = " << num1+num2 << '\n'
        << num1 << " - " << num2 << " = " << num1-num2 << '\n';
    return 0;
}
