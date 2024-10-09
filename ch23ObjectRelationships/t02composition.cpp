#include <cstdlib>
#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

struct Point2D {
    int32_t x;
    int32_t y;
};

std::ostream& operator<<(std::ostream& out, const Point2D& point) {
    return out << '(' << point.x << ", " << point.y << ')';
}

class Creature {
    std::string name_;
    Point2D location_;
public:
    Creature(std::string_view name, const Point2D& location)
        : name_{ name }, location_{ location }
    { }

    friend std::ostream& operator<<(std::ostream& out, const Creature& creature) {
        return out << creature.name_ << " is at " << creature.location_;
    }

    void moveTo(int32_t x, int32_t y) {
        location_.x = x;
        location_.y = y;
    }
};

int main() {
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature( name, { 4, 7 } );
    for (;;) {
        std::cout << creature << "\n"
                     "Enter bew X location for creature (-1 to quit): ";
        int32_t x{ 0 };
        std::cin >> x;
        if (x == -1)
            break;
        std::cout << "Enter new X location for creature (-1 to quit): ";
        int32_t y{ 0 };
        std::cin >> y;
        if (x == -1)
            break;
        creature.moveTo(x, y);
    }
    return EXIT_SUCCESS;
}
