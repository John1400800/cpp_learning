#include <cstdlib>
#include <string>
#include <string_view>
#include <iostream>

class Person {
private:
    std::string name{};
public:
    void kisses(const Person& other) const {
        std::cout << name << " kisses " << other.name;
    }
    void setName(std::string_view newName) {
        name = newName;
    }
};

int main() {
    Person joe;
    joe.setName("Joe");
    Person kate;
    kate.setName("Kate");
    joe.kisses(kate);
    return EXIT_SUCCESS;
}
