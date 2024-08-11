#include <cstdlib>
#include <vector>
#include <iostream>
// CTAD can't be used in function parameter using func template
//                               VVVV
void passByRef(const std::vector<auto>& vec) {
    if (std::size(vec)>=1)
        std::cout << vec[0] << '\n';
}

int main() {
    std::vector prime{2, 3, 5}; // <<< use CTAD(class template argument deduction)
    passByRef(prime);
    return EXIT_SUCCESS;
}
