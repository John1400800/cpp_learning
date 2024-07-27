#include <cstdlib>
#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

class Employee {
    std::string name{};
    uint32_t id{};
public:
    Employee(std::string_view initName)
        : Employee{initName, 0} {
    }
    Employee(std::string_view initName, uint32_t initId)
        : name{ initName }, id{ initId } {
        std::cout << "Employee " << name << " created\n";
    }
};

int main() {
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
    return EXIT_SUCCESS;
}
