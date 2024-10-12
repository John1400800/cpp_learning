#include <cstdlib>
#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

class Person {
    std::string name_{};
    uint16_t    age_{};
public:
    Person(std::string_view name="", uint16_t age=0)
        : name_{ name }, age_{ age }
    { }

    const std::string& getName() const {
        return name_;
    }

    uint16_t getAge() const {
        return age_;
    }
};

class BaseballPlayer : public Person {
    double battingAverage_{};
    uint16_t     homeRuns_{};
public:
    BaseballPlayer(std::string_view name="", uint16_t age=0, double battingAverage=0.0, uint16_t homeRuns=0)
        : Person( name, age ),
          battingAverage_{ battingAverage },
          homeRuns_{ homeRuns }
    { }

    double getBattingAverage() const {
        return battingAverage_;
    }

    uint16_t getHomeRuns() const {
        return homeRuns_;
    }
};

std::ostream& operator<<(std::ostream& out, const Person& person) {
    return out << "Person with name: " << person.getName() << ", " << person.getAge() << " years old";
}

std::ostream& operator<<(std::ostream& out, const BaseballPlayer& bPlayer) {
    return out << static_cast<const Person&>(bPlayer)
        << " who play baseball with: " << bPlayer.getBattingAverage() << " average batting and " << bPlayer.getHomeRuns() << " home runs";
}

int main() {
    BaseballPlayer frank{ "Frank", 18, 20.25, 12345 };
    std::cout << frank << '\n';
    return EXIT_SUCCESS;
}
