#include <cfloat>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <iostream>

uint8_t getOperator();
double getNumber();

int main() {
    double num1       {     getNumber() };
    uint8_t operation {   getOperator() };
    double num2       {     getNumber() };
    while (operation=='/' && num2==0.) {
        std::cout << "The denominator cannot be zero.  Try again.\n";
        num2 = getNumber();
    }
    std::cout<<num1<<' '<<operation<<' '<<num2<<" is ";
    switch (operation) {
    case '+':
        std::cout<<num1+num2<<'\n';
        break;
    case '-':
        std::cout<<num1-num2<<'\n';
        break;
    case '*':
        std::cout<<num1*num2<<'\n';
        break;
    case '/':
        std::cout<<num1/num2<<'\n';
        break;
    }
    return EXIT_SUCCESS;
}

namespace {
    bool clearFailedExtraction();
}

uint8_t getOperator() {
    std::cout << "Enter one of the following: +, -, *, or /: ";
    while (true) {
        uint8_t operation{};
        std::cin>>operation;
        if (!clearFailedExtraction())
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (operation) {
            case '+': case '-': case '*': case '/': 
                return operation;
            default:
                std::cout<<"try again: ";
                continue;
        }
    }
}

double getNumber() {
    std::cout<<"enter decimal number: ";
    while (true) {
        double number{};
        std::cin>>number;
        if (clearFailedExtraction()) {
            std::cout<<"try again: ";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return number;
    }
}

namespace {
    bool clearFailedExtraction() {
        if (!std::cin) {
            if (std::cin.eof())
                exit(0);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }
        return false;
    }
}
