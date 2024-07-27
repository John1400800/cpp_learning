#include <cstdlib>
#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

class Employee {
    static constexpr uint32_t defaultId{ 0 };

    std::string name{defaultId};
    uint32_t id{};
public:
    Employee() = default;
    Employee(std::string_view initName, uint32_t initId=defaultId)
        : name{ initName }, id{ initId } {
        std::cout << "Employee " << name << " created\n";
    }
};

int main() {
    Employee e1;
    Employee e2{ "James" };
    Employee e3{ "Dave", 42 };
    return EXIT_SUCCESS;
}
