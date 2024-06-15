#include <c++/13.2/iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    std::cout << "Double "<< num << " is: " << num*2 << '\n'
        << "Triple " << num << " is: " << num*3 << std::endl;
    return 0;
}
