#include <cstdlib>
#include <cstdint>
#include <iostream>

class PoweredDevice {
public:
    PoweredDevice(uint32_t power) {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner: virtual public PoweredDevice {
public:
    Scanner(uint32_t scanner, uint32_t power)
        : PoweredDevice{ power }
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: virtual public PoweredDevice {
public:
    Printer(uint32_t printer, uint32_t power)
        : PoweredDevice{ power }
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer {
public:
    Copier(uint32_t scanner, uint32_t printer, uint32_t power)
        : PoweredDevice{ power }, Scanner{ scanner, power }, Printer{ printer, power }
    { }
};

int main() {
    Copier copier{ 1, 2, 3 };
    return EXIT_SUCCESS;
}
