#define NEED__DATE_H
#ifdef NEED__DATE_H
#include "date.h"
#include <cstdint>
#include <iostream>
Date::Date (uint16_t year, uint8_t month, uint8_t day)
    : year_{year}, month_{month}, day_{day}
{}

Date& Date::year(uint16_t year) {
    year_ = year;
    return *this;
}

Date& Date::month(uint8_t month) {
    month_ = month;
    return *this;
}

Date& Date::day(uint8_t day) {
    day_ = day;
    return *this;
}

const Date& Date::print() const {
    std::cout << static_cast<uint16_t>(day_)   << "."
              << static_cast<uint16_t>(month_) << "."
              << year_ << "\n";
    return *this;
}

const Date& print(const Date& date) {
    return date.print();
}
#endif /* NEED__DATE_H */
