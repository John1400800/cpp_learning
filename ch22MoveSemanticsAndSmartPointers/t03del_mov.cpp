#include <cstdlib>
#include <string>
#include <string_view>
#include <iostream>

class Name {
    std::string name_{};
public:
    Name(std::string_view name)
        : name_{ name }
    { }
    Name(const Name&) = default;
    Name& operator=(const Name&) = default;
    Name(Name&&) = delete;
    Name& operator=(Name&&) = delete;
    const std::string& operator*() const {
        return name_;
    }
};

Name getJoe() {
    Name joe{ "Joe" };
    return joe;
}

int main() {
    Name name{ getJoe() };
    std::cout << *name << '\n';
    return EXIT_SUCCESS;
}
