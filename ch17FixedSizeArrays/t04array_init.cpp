#include <cstdlib>
#include <cstdint>
#include <array>
#include <string_view>
#include <iostream>

struct Student {
    uint32_t id{};
    std::string_view name{};
};

namespace {
    constexpr std::string_view nobody{ "nobody" };
    constexpr std::array<Student, 3> students{{
        {0, "Alex"},
        {1, "Joe"},
        {2, "Bob"}
    }};
}

const Student* findStudentById(uint32_t id);

int main() {
    const Student* student1{ findStudentById(1) };
    std::cout << "You found: " << (student1? student1->name : nobody) << '\n';
    const Student* student2{ findStudentById(3) };
    std::cout << "You found: " << (student2? student2->name : nobody) << '\n';
    return EXIT_SUCCESS;
}

const Student* findStudentById(uint32_t id) {
    for (auto& student : students)
        if (student.id == id)
            return &student;
    return nullptr;
}


