#include <cstdint>
#include <cstdlib>
#include <iostream>

class Storage;

class Display {
    bool displayIntFirst_{};
public:
    Display(bool displayIntFirst) : displayIntFirst_{displayIntFirst} {}
    void displayStorage(const Storage& storage);
    void setDisplayIntFirst(bool isFirst=true) {
        displayIntFirst_ = isFirst;
    }
};

class Storage {
    uint32_t nValue_{};
    double dValue_{};
public:
    Storage(uint32_t nValue, double dValue) : nValue_{nValue}, dValue_{dValue} {};
    friend void Display::displayStorage(const Storage& storage);
};

void Display::displayStorage(const Storage& storage) {
    if (displayIntFirst_)
        std::cout << storage.nValue_ << ' ' << storage.dValue_ << '\n';
    else
        std::cout << storage.dValue_ << ' ' << storage.nValue_ << '\n';
}

int main() {
    Storage storage{1, 2.5};
    Display display{false};
    display.displayStorage(storage);
    display.setDisplayIntFirst();
    display.displayStorage(storage);
    return EXIT_SUCCESS;
}
