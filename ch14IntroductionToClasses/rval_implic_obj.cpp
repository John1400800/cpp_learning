#include <cstdint>
#include <cstdlib>
#include <string>
#include <iostream>

/* A reference to a member of an rvalue object
 * can only be safely used within the full
 * expression where the rvalue object is created.
 */

class Foo {
private:
    std::string value{};
public:
    const auto& getValue() const {
        return value;
    }
    void setValue(std::string_view newValue) {
        value = newValue;
    }
};

Foo createFoo() {
    Foo foo;
    foo.setValue("Hello world");
    return foo;
}

int main() {
    auto& someFoo{ createFoo().getValue() };    // Rvalue implicit objects
    std::cout << someFoo << '\n';               // undefined behavior
    return EXIT_SUCCESS;
}
