#include <cstdlib>      // for EXIT_SUCCESS
#include <iostream>     // for cin/cout

#include "structs.hpp"

int main(int32_t, const char**) {
    Array<double> arr1, arr2;
    initArray(arr1, {1., 2., 3.});
    std::cout << arr1 << '\n';
       std::cout  << arr2 << '\n';
    moveArray(arr2, arr1);
    resizeArray(arr2, 5);
    insertBeforeIdxInArr(arr2, 5., 4);
    removeIdxArr(arr2, 0);
    std::cout << arr1 << '\n';
        std::cout << arr2 << '\n';
    return EXIT_SUCCESS;
}

