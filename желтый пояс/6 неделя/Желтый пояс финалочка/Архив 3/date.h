#pragma once
#include "iostream"
#include <iomanip>


using namespace std;


using namespace std;

class Date {
public:
    Date(const int& NewYear, const int& NewMonth, const int& NewDay);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int year;
    int month;
    int day;
};

Date ParseDate(istream& is);

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& os, const Date& date);



