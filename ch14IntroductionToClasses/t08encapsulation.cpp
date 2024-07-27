#include <cstdlib>
#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

class Employee {
    std::string name{};
    char firstInitial{};
public:
    void setName(std::string_view newName) {
        name = newName;
        firstInitial = name.front();
    }
    void printNameWithInitials() const {
        std::cout << "Enployee " << name
            << " has first initial " << firstInitial << '\n';
    }
};

int main() {
    Employee e{};
    e.setName("John");
    e.printNameWithInitials();
    return EXIT_SUCCESS;
}
