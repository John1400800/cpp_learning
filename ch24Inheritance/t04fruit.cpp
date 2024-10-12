#include <cstdlib>
#include <string>
#include <string_view>
#include <iostream>

class Fruit {
protected:
    std::string_view fruitName_{};
    std::string name_{};
    std::string color_{};
public:
    Fruit(std::string_view fruitName, std::string_view name, std::string_view color)
        : fruitName_{ fruitName }, name_{ name }, color_{ color }
    { }

    virtual void print(std::ostream& out) const {
        out << fruitName_ << ": ( " << name_ << ", " << color_;
    }

    virtual ~Fruit() = default;
};

std::ostream& operator<<(std::ostream& out, const Fruit& fruit) {
     fruit.print(out);
     return out;
}

class Apple : public Fruit {
    static constexpr std::string_view fruitName{ "Apple" };
    double fiber_{};
public:
    Apple(std::string_view name, std::string_view color, double fiber)
        : Fruit(fruitName, name, color), fiber_{ fiber }
    { }

    void print(std::ostream& out) const override {
        Fruit::print(out);
        out << ", " << fiber_ << " )";

    }
};

class Banana : public Fruit {
    static constexpr std::string_view fruitName{ "Banana" };
public:
    Banana(std::string_view name, std::string_view color)
        : Fruit(fruitName, name, color)
    { }

    void print(std::ostream& out) const override {
        Fruit::print(out);
        out << " )";
    }
};

int main() {
    const Apple  a{ "Red delicius ", "red", 4.2 };
    std::cout << a << '\n';
    const Banana b{ "Cavedish", "yellow" };
    std::cout << b << '\n';
    return EXIT_SUCCESS;
}
