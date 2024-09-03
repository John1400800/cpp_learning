#include <cstdlib>
#include <cstdint>
#include <chrono>
#include <random>
#include <limits>
#include <array>
#include <string>
#include <string_view>
#include <iostream>

namespace Randgen {
    std::mt19937 helpInitMt() {
        std::random_device rd{};
        std::seed_seq seedSeq{
            static_cast<std::seed_seq::result_type>(
                    std::chrono::steady_clock::now().time_since_epoch().count(),
                    rd(), rd(), rd(), rd(), rd(), rd(), rd() )
        };
        return std::mt19937{ seedSeq };
    }

    std::mt19937 state{ helpInitMt() };

    template <typename T>
    T get(const T& min, const T& max) {
        return std::uniform_int_distribution<T>( min, max )(state);
    }
};

namespace Potion {
    enum Type {
        healing,
        mana,
        speed,
        invisibility,
        max_potions
    };
    constexpr std::array types { healing, mana, speed, invisibility };
    constexpr std::array<std::string_view, max_potions> name {
        "healing", "mana", "speed", "invisibility"
    };
    constexpr std::array<uint32_t, max_potions> cast { 20, 30, 12, 50};
    static_assert(std::size(types)==max_potions);
    static_assert(std::size(name)==max_potions);
    static_assert(std::size(cast)==max_potions);
};

class Player {
    static constexpr uint32_t minStartingGold{  80 };
    static constexpr uint32_t maxStartingGold{ 120 };
    std::string name_{};
    uint32_t gold_{};
    std::array<uint32_t, Potion::max_potions> inventory_{};
public:
    explicit Player(std::string_view name)
        : name_{name}
        , gold_{Randgen::get(minStartingGold, maxStartingGold)}
        {}
    bool buy(Potion::Type type) {
        if (gold_ < Potion::cast[type])
            return false;
        gold_ -= Potion::cast[type];
        ++inventory_[type];
        return true;
    }
    uint32_t gold() const {
        return gold_;
    }
    uint32_t inventory(Potion::Type potion) const {
        return inventory_[potion];
    }
};

Potion::Type whichPotion() {
    std::cout << "Enter the number of the potion you'd like to buy, "
        "or 'q' to quit: ";
    char input{};
    while (true) {
        std::cin >> input;
        if (!std::cin)
            std::cin.clear();
        else if (input == 'q')
            return Potion::max_potions;
        else if (input-'0' >= 0 && input-'0' < Potion::max_potions)
            return static_cast<Potion::Type>(input-'0');
        std::cout << "I didn't understand what you said.  Try again: ";
        std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n');
    }
}

void shop(Player& player) {
    while (true) {
        std::cout << "Hear is our selection for today\n";
        for (auto potion : Potion::types)
            std::cout << potion << ")" << " " << Potion::name[potion]
                << " cast "<< Potion::cast[potion] << '\n';
        Potion::Type which{ whichPotion() };
        if (which == Potion::max_potions)
            return ;
        if (!player.buy(which))
            std::cout << "You can not afford that.\n\n";
        else
            std::cout << "You purchased a potion of " << Potion::name[which] << ".  You have " << player.gold() << " gold left.\n\n";
    }
}

void printInventory(Player& player) {
    std::cout << "your inventory contains: \n";
    for (auto potion : Potion::types)
        if (player.inventory(potion) > 0)
            std::cout << player.inventory(potion) << "x potion of "
                << Potion::name[potion] << '\n';

    std::cout << "You escaped with " << player.gold() << " gold remaining.\n";
}

int main() {
    std::cout << "Welcome to Rascoe's potion emporiom!\n"
        "Enter your name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    Player player{ name };
    std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n";
    shop(player);
    printInventory(player);
    std::cout << "Thanks for shopping at Roscoe's potion emporium!\n";
    return EXIT_SUCCESS;
}
