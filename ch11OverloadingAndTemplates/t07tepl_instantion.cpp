#include <cstdint>
#include <cstdlib>
#include <iostream>

#define PrintExpr(Expr)                 \
do {                                    \
    std::cout<<#Expr": "<<(Expr)<<'\n'; \
} while(false)

template <typename Type>
Type max(Type a, Type b);

int max(int a, int b);

int main() {
    PrintExpr(max<>(1, 2));
    return EXIT_SUCCESS;
}

template <typename Type>
Type max(Type a, Type b) {
    std::cout << "called max<Type>(Type a, Type b)\n";
    return a>b?a:b;
}

int max(int a, int b) {
    std::cout << "called max(int a, int b)\n";
    return a>b?a:b;
}
