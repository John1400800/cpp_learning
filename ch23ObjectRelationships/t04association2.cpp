#include <cstdlib>
#include <string>
#include <string_view>
#include <iostream>

class Car {
    std::string name_{};
    size_t      id_{};
public:
    Car(std::string_view name, size_t id)
        : name_{ name }, id_{ id }
    { }

    const std::string& getName() const  { return name_; }
    size_t getId()                      { return id_;   }
};

namespace CarLot {
    Car carLot[4] { { "Prius", 4    },
                    { "Corolla", 17 },
                    { "Accord", 84  },
                    { "Matrix", 62  } };

    Car *getCarById(size_t id) {
        for (auto& car : carLot)
            if (car.getId() == id)
                return &car;
        return nullptr;
    }
};

class Driver {
    std::string name_{};
    size_t      carId_{};
public:
    Driver(std::string_view name, size_t carId)
        : name_{ name }, carId_{ carId }
    { }

    const std::string& getName()        { return name_;  }
    size_t getCarId() const             { return carId_; }
};

int main() {
    Driver d{ "Franz", 17 };
    Car *driverCar{ CarLot::getCarById(d.getCarId()) };
    std::cout << d.getName();
    if (driverCar)
        std::cout << " is driving a " << driverCar->getName() << '\n';
    else
        std::cout << d.getName() << " couldnt't find his car\n";
    return EXIT_SUCCESS;
}
