#include <cstdint>
#include <cstdlib>
#include <iostream>

class Fruit {
public:
    using Percentage = uint16_t;
    enum Type { // Second, nested type Type has been defined at the
        apple,  // top of the class. Nested type names must be fully
        banana, // defined before they can be used, so they are
        cherry  // usually defined first.
    };
private:
    Type type_{};
    Percentage percEaten{ 0 };

public:
    Fruit(Fruit::Type type)
        : type_{type} {}

    Fruit::Type getType() const {
        return type_;
    }

    Percentage getPercentageEaten() const {
        return percEaten;
    }

    bool isCherry() const {
        return type_ == cherry;
    }
    bool eat(Percentage eatPerc) {
        if (percEaten + eatPerc <= 100) {
            percEaten += eatPerc;
            return true; // successfully eaten
        }
        return false;    // nothing to eat
    }
};

int main() {
    Fruit apple{ Fruit::apple };
    apple.eat(25);
    if (apple.getType() == Fruit::apple) {
        std::cout << "This apple is ";
        Fruit::Percentage applePercentageEaten = apple.getPercentageEaten();
        if (applePercentageEaten > 0)
            std::cout << applePercentageEaten << " percent eaten\n";
        else
            std::cout << "not eaten\n";
    } else
        std::cout << "It's not an apple at all\n";
    return EXIT_SUCCESS;
}
