#ifndef DATE_H
#define DATE_H
#include <cstdint>

class Date {
    uint16_t year_{};
    uint8_t  month_{};
    uint8_t  day_{};
public:
    Date(uint16_t year, uint8_t month, uint8_t day);
    Date& year(uint16_t year);
    Date& month(uint8_t month);
    Date& day(uint8_t day);
    const Date& print() const;
    friend const Date& print(const Date& date);
};
#endif /* DATE_H */
