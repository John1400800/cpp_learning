#include <cstdint>
#include <cstdint>
#include <iostream>
#include <iomanip>

class Date {
private:
    uint32_t    m_year{};
    uint8_t     m_month{};
    uint8_t     m_day{};
public:
    void        setYear(uint32_t year)  { m_year = year;   }
    uint32_t    getYear() const         { return m_year;   }
    void        setMonth(uint8_t month) { m_month = month; }
    uint16_t    getMonth() const        { return m_month;  }
    void        setDay(uint8_t day)     { m_day = day;     }
    uint16_t    getDay() const          { return m_day;    }
    void        print() const {
        using namespace std;
        std::cout << setfill('0') << setw(2) << getDay() << '/'
            << setfill('0') << setw(2) << getMonth() << '/'
            << setw(4) << getYear() << '\n';
    }
};

int main() {
    Date today;
    today.setDay(23);
    today.setMonth(9);
    today.setYear(2024);
    today.print();
    return EXIT_SUCCESS;
}
