#include <c++/13.2/iostream>
#include <stdlib.h>

using std::cin, std::cout;

int getValueFromUser();
int doubleNumber(int);

int main() {
    cout << doubleNumber(getValueFromUser()) << '\n';
    return EXIT_SUCCESS;
}

int getValueFromUser() {
    cout << "Enter an integer: ";
    int input{};
    cin >> input;
    return input;
}

int doubleNumber(int num) {
    return num * 2;
}
