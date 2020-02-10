#include "phone_number.h"
#include <sstream>
#include <iostream>


//void EnsureNextSymbolAndSkip(stringstream& stream, const string& s) {
//    if (stream.peek() != '-') {
//        throw invalid_argument("Wrong date format: " + s);
//    }
//    stream.ignore(1);
//}

PhoneNumber::PhoneNumber(const string &international_number) {
    stringstream ss(international_number);
    if (ss.peek() != '+') {
        throw invalid_argument("Wrong date format: " + international_number);
    } else {
        ss.ignore(1);
    }
    if (getline(ss, country_code_, '-')) {

    } else {
        throw invalid_argument("Wrong date format: " + international_number);
    }
    if (!getline(ss, city_code_, '-')) {
        throw invalid_argument("Wrong date format: " + international_number);
    }
    if (!getline(ss, local_number_)) {
        throw invalid_argument("Wrong date format: " + international_number);
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}

//int main() {
//    PhoneNumber pn("+1-2-coursera-cpp");
//    cout << pn.GetCountryCode() << pn.GetCityCode() << pn.GetLocalNumber() << endl;
//    cout << pn.GetInternationalNumber();
//    return 0;
//}