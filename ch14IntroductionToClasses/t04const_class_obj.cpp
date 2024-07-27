#include <cstdlib>
#include <cstdint>
#include <iostream>

class Date {
private:
    uint16_t year{};
    uint16_t month{};
    uint16_t day{};
public:
    void print() const {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main() {
    const Date today{ 2024, 9, 22 };
    today.print();
    return EXIT_SUCCESS;
}
