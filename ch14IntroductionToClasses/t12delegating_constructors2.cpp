#include <cstdlib>
// #include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

class Ball;
void printBall(const Ball* ball);
void printBall(const Ball& ball);

class Ball {
    static constexpr std::string_view defColor{ "black" };
    static constexpr double           defRadius{ 10.0 };
    std::string color { defColor  };
    double      radius{ defRadius };
public:
    Ball(double iniRadius)
        : Ball{ defColor, iniRadius } {}
    Ball(std::string_view iniColor=defColor, double iniRadius=defRadius)
        : color{ iniColor }, radius{ iniRadius } {
            printBall(this);
        }
    const std::string& getColor() const {
        return color;
    }
    double getRadius() const {
        return radius;
    }
};

int main() {
    printBall();
    Ball defaultBall{};
    Ball blueBall{ "blue" };
    Ball twentyBall{ 20.0 };
    Ball blueTwentyBall{"blue", 20.0 };
    return EXIT_SUCCESS;
}

void printBall(const Ball* ball) {
    std::cout << "Ball(" << ball->getColor() << ", " << ball->getRadius() << ")\n";
}

void printBall(const Ball& ball) {
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}

