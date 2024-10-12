#include <cstdlib>
#include <cstdint>
#include <string>
#include <string_view>
#include <iostream>

struct Point2D {
    int32_t x{}, y{};
};

class Box {
public:
    void setTopLeft(Point2D point) { m_topLeft = point; }
    void setBottomRight(Point2D point) { m_bottomRight = point; }
private:
    Point2D m_topLeft{};
    Point2D m_bottomRight{};
};

class Label {
public:
    void setText(const std::string_view str) { m_text = str; }
    void setFontSize(uint32_t fontSize) { m_fontSize = fontSize; }
private:
    std::string m_text{};
    uint32_t m_fontSize{};
};

class Tooltip {
public:
    void setText(const std::string_view str) {m_text = str; }
private:
    std::string m_text{};
};

class Button: public Box, public Label, public Tooltip {};

int main() {
    Button button{};
    button.Box::setTopLeft({ 1, 1 });
    button.Box::setBottomRight({ 10, 10 });
    button.Label::setText("Submit");
    button.Label::setFontSize(6);
    button.Tooltip::setText("Submit form to the server");
}
