#include <cstdlib>
#include <optional>
#include <algorithm>
#include <limits>
#include <string>
#include <string_view>
#include <iostream>

enum class Pet {
    cat,
    dog,
    pig,
    whale,
};

std::string toASCIILowerCase(std::string_view str);
std::ostream& operator<<(std::ostream& out, Pet pet);
std::istream& operator>>(std::istream& in, Pet& pet);

constexpr std::optional<Pet> getPetByStr(std::string_view sv) {
    using enum Pet;
#define RET_ENUM(str) if (sv == #str) return (str)
    RET_ENUM(cat   );
    RET_ENUM(dog   );
    RET_ENUM(pig   );
    RET_ENUM(whale );
#undef  RET_ENUM
    return std::nullopt;
}

constexpr std::optional<std::string_view> getStrByPet(Pet pet) {
    switch (pet) {
    using enum Pet;
#define RET_STR(en) case (en): return #en
    RET_STR(cat   );
    RET_STR(dog   );
    RET_STR(pig   );
    RET_STR(whale );
#undef RET_STR
    default: return std::nullopt;
    }
}

int main() {
    bool isFirstTry{ true };
    Pet pet{};
    do {
        if (isFirstTry) {
            isFirstTry = false;
            std::cout << "Enter a pet: ";
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You entered an invalid pet try again: ";
        }
        std::cin >> pet;
    } while (!std::cin);
    std::cout << "You entered: " << pet << "\n";
    return EXIT_SUCCESS;
}

std::ostream& operator<<(std::ostream& out, Pet pet) {
    std::optional<std::string_view> petName{ getStrByPet(pet) };
    if (petName)
        out << *petName;
    else
        out << "Pet::???";
    return out;
}

std::istream& operator>>(std::istream& in, Pet& pet) {
    std::string petName{};
    in >> petName;
    std::optional<Pet> match{ getPetByStr(toASCIILowerCase(petName)) };
    if (match)
        pet = *match;
    else 
        in.setstate(std::ios_base::failbit);
    return in;
}

std::string toASCIILowerCase(std::string_view sv) {
    std::string lower{};
    std::transform(sv.begin(), sv.end(), std::back_inserter(lower), ::tolower);
    return lower;
}
