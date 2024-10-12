#include <cstdlib>
#include <iostream>

class A {
public:
    A() {
        std::cout << "A\n";
    }
};

class B : public A {
public:
    B() {
        std::cout << "B\n";
    }
};

class C : public B {
public:
    C() {
        std::cout << "C\n";
    }
};

class D : public C{
public:
    D() {
        std::cout << "D\n";
    }
};

int main() {
    std::cout << "Construction: A:\n";
    A a;
    std::cout << "Construction: B:\n";
    B b;
    std::cout << "Construction: C:\n";
    C c;
    std::cout << "Construction: D:\n";
    D d;
    return EXIT_SUCCESS;
}
