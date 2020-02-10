#include "database.h"

ostream& operator<<(ostream& os, const pair<Date, vector<string>> item) {
    for (auto event : item.second) {
        os << item.first << " " << event;
        if (event != *(--item.second.end())) {
            os << endl;
        }
    }
    return os;
}

ostream& operator<<(ostream& os, const pair<Date, string> item) {
    os << item.first << " " << item.second;
    return os;
}

void Database::Add(const Date& date, const string& event) {
    auto& s = date_to_events_set[date];
    auto it = s.lower_bound(event);
    if (*it != event) {
        s.insert(it, event);
        date_to_events[date].push_back(event);
    }
}

void Database::Print(ostream& os) const {
    for (auto item : date_to_events) {
        os << item << endl;
    }
}

//pair<Date, string> Database::Last(const Date& date) const {
////        auto it = date_to_events.lower_bound(date);
////        if (it == date_to_events.end()) {
////            throw invalid_argument("No element");
////        } else {
////            return make_pair(date, *(it->second.end() - 1));
////        }
//    auto it = date_to_events.upper_bound(date);
//    if (it != date_to_events.begin()) {
//        --it;
//        return make_pair(it->first, *(it->second.end() - 1));
//    } else {
//        throw invalid_argument("No element");
//    }
//}

pair<Date, string> Database::Last(const Date &date) const {
    if (date < date_to_events.begin()->first || date_to_events.empty()) {
        throw invalid_argument("");
    };
    auto it = --(date_to_events.upper_bound(date));
    return {it->first, it->second.back()};
};

//TestParseEvent OK
//TestParseCondition OK
//Add 2017-11-21 Tuesday
//        Add 2017-11-20 Monday
//        Add 2017-11-21 Weekly meeting
//Print
//        Find event != "Weekly meeting"
//Last 2017-11-30
//Del date > 2017-11-20
//Last 2017-11-30
//Last 2017-11-01

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


