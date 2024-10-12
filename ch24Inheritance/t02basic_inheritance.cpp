#include <cstdlib>
#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

struct Person {
    std::string name_{};
    uint16_t    age_{};

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

struct Employee : public Person {
    double      hourlySalary_{};
    size_t      employeeId_{};

    Employee(double hourlySalary=0.0, size_t employeeId=0)
        : hourlySalary_{ hourlySalary }, employeeId_{ employeeId }
    { }

    friend std::ostream& operator<<(std::ostream& out, const Employee& empl) {
        return out << empl.name_ << ": " << empl.hourlySalary_;
    }
};

class Supervisor : public Employee {
    size_t overseesIds[5]{};
};

struct BaseballPlayer : public Person {
    double battingAverage_{};
    uint16_t     homeRuns_{};

    BaseballPlayer(double battingAverage=0.0, uint16_t homeRuns=0)
        : battingAverage_{ battingAverage }, homeRuns_{ homeRuns }
    { }
};

int main() {
    Employee frank{ 20.25, 12345 };
    frank.name_ = "Frank";
    std::cout << frank << '\n';
    return EXIT_SUCCESS;
}
