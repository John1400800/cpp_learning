#include <cstdlib>
#include <string>
#include <string_view>
#include <iostream>

class Ball {
    std::string color{};
    double      radius{};
public:
    Ball() = default;
    Ball(std::string_view newColor, double newRadius) : color{ newColor }, radius{ newRadius } {}
    const std::string& getColor() const {
        return color;
    }
    double getRadius() const {
        return radius;
    }
};

void print(const Ball& ball) {
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}

int main() {
    Ball ball{};
    print(ball);
    return EXIT_SUCCESS;
}
