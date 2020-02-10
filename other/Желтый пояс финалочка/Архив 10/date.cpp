#include "date.h"

Date::Date(const int &NewYear, const int &NewMonth, const int &NewDay)  :
        year(NewYear), month(NewMonth), day(NewDay){};
int Date::GetDay() const {return day;}
int Date::GetMonth() const {return month;}
int Date::GetYear() const {return year;}

int DaysCount(const Date& date) {
    return date.GetMonth() * 31 + date.GetDay();
}

bool operator==(const Date& lhs, const Date& rhs) {
    return (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear()) {
        return true;
    } else if (lhs.GetYear() == rhs.GetYear()){
        return DaysCount(lhs) < DaysCount(rhs);
    } else
        return false;
}

bool operator<=(const Date& lhs, const Date& rhs) {
    if (lhs < rhs || lhs == rhs) {
        return true;
    } else
        return false;
}

bool operator>(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() > rhs.GetYear()) {
        return true;
    } else if (lhs.GetYear() == rhs.GetYear()){
        return DaysCount(lhs) > DaysCount(rhs);
    } else
        return false;
}

bool operator>=(const Date& lhs, const Date& rhs) {
    if (lhs > rhs || lhs == rhs) {
        return true;
    } else
        return false;
}
//
//2017-11-20 Monday
//2017-11-21 Tuesday
//2017-11-21 Weekly meeting
//2017-11-20 Monday
//2017-11-21 Tuesday
//        Found 2 entries
//2017-11-21 Weekly meeting
//Removed 2 entries
//2017-11-20 Monday
//        No entries


bool operator!=(const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}

Date ParseDate(istream& is) {
    int year, month, day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    return Date(year, month, day);
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0');
    os << setw(4) << date.GetYear() << "-" << setw(2) << date.GetMonth()
       << "-" << setw(2) << date.GetDay();
    return os;
}
