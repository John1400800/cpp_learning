#include <cstdlib>
#include <iostream>
class Humidity; // forward declaration of Humidity

class Temperature {
    using degrees = double;
    degrees temperature_{0};
public:
    explicit Temperature(degrees temperature);
    friend void printWeather(const Temperature& temp, const Humidity& humidity);
};
class Humidity {
    using percentage = double;
    percentage humidity_{0};
public:
    explicit Humidity(percentage humidity);
    friend void printWeather(const Temperature& temp, const Humidity& humidity);
};

Temperature::Temperature(degrees temperature) : temperature_{temperature} {}

Humidity::Humidity(percentage humidity) : humidity_{humidity} {}

// In more complex cases, it may be preferable to use friendship
// instead of adding many new access functions to the interface of a
// class.
void printWeather(const Temperature& temp, const Humidity& humidity) {
    std::cout << "The temperature is " << temp.temperature_
        << "°C and the humidity is " << humidity.humidity_ << "%\n";
}

int main() {
    Temperature temp(18.5);
    Humidity hum{10};
    printWeather(temp, hum);
    return EXIT_SUCCESS;
}
