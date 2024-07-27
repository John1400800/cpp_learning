#include <cstdint>
#include <cstdlib>
#include <iostream>

inline namespace Gravity {
    constexpr float gravity{ 9.8f };
}

constexpr float calcBallHeight(float towerHeight, float timeSec) {
    float ballHeigh = towerHeight - timeSec*timeSec*gravity/2.f;
    return ballHeigh>=0.f ? ballHeigh : 0.f;
}

int main() {
    std::cout<<"Enter the height of the tower in meters: ";
    float towerHeight{};
    std::cin>>towerHeight;
    for (uint8_t seconds{ 0 }; seconds<=10; ++seconds) {
        std::cout<<"At "<<static_cast<int>(seconds)<<" seconds, the ball is ";
        float ballHeigh = calcBallHeight(towerHeight, static_cast<float>(seconds));
        if (ballHeigh==0.f) {
            std::cout<<"on ground.\n";
            break;
        } else
            std::cout<<"at height "<<ballHeigh<<" meters.\n";
    }
    return EXIT_SUCCESS;
}
