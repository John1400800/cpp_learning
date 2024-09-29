#include <cstdlib>
#include <cstdint>
#include <iostream>

int main() {
    uint32_t ammo{ 10 };
    auto shoot{
        [&ammo]() {
            if (ammo > 0)
                --ammo;
            std::cout << "Pew! " << ammo << " shot(s) left.\n";
    }};
    shoot();
    std::cout << ammo << " shot(s) left.\n";
    return EXIT_SUCCESS;
}
