#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Date {
public:
    Date(const int& NewYear, const int& NewMonth, const int& NewDay) {
        year = NewYear;
        month = NewMonth; // планирую тут сделать конверт из стринга в инт, конструктор принимает также стринг
        day = NewDay;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    int lhs_sum = lhs.GetYear() * 365 + lhs.GetMonth() * 31 + lhs.GetDay();
    int rhs_sum = rhs.GetYear() * 365 + rhs.GetMonth() * 31 + rhs.GetDay();
    return (lhs_sum < rhs_sum);
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        date_to_events[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (date_to_events.count(date) == 0) {
            return false;
        } else if (date_to_events[date].count(event) == 0) {
            return false;
        } else {
            date_to_events[date].erase(event);
            return true;
        }
    }

    int DeleteDate(const Date& date) {
        if (date_to_events.count(date) == 0) {
            return 0;
        } else {
            int i = date_to_events[date].size();
            date_to_events[date].clear();
            return i;
        }
    }

    void Find(const Date& date) const {
        if (date_to_events.count(date) != 0) {
            for (string item : date_to_events.at(date)) {
                cout << item << endl;
            }
        }
    }

    void Print() const {
        for (auto item : date_to_events) {
            for (auto event : item.second) {
                cout << setfill('0');
                cout << setw(4) << item.first.GetYear() << "-" << setw(2) << item.first.GetMonth()
                     << "-" << setw(2) << item.first.GetDay() << " " << event << endl;
            }
        }
    }

private:
    map <Date, set <string>> date_to_events;
};
//
//vector <string> split(const string& command) {
//    stringstream ss(command);
//    vector <string> vec_commands;
//    string item;
//    int v;
//    cin >> item;
//    vec_commands.insert(begin(vec_commands), item);
//
//}
//
//istream operator >>()

void EnsureNextSymbolAndSkip(stringstream& stream, const string& s) {
    if (stream.peek() != '-') {
        throw runtime_error("Wrong date format: " + s);
    }
    stream.ignore(1);
}

Date ParseDate(const string& s) {
    stringstream ss(s);
    int year, month, day;
    if (ss >> year) {
        EnsureNextSymbolAndSkip(ss, s);
    } else {
        throw runtime_error("Wrong date format: " + s);
    }
    if (ss >> month) {
        EnsureNextSymbolAndSkip(ss, s);
    } else {
        throw runtime_error("Wrong date format: " + s);
    }
    if (ss >> day) {
    } else {
        throw runtime_error("Wrong date format: " + s);
    }
    string k;
    ss >> k;
    if (k != "") {
        throw runtime_error("Wrong date format: " + s);
    }
    if (month <= 0 || month > 12) {
        throw runtime_error("Month value is invalid: " + to_string(month));
    }
    if (day <= 0 || day > 31) {
        throw runtime_error("Day value is invalid: " + to_string(day));
    }
    Date date(year, month,day);
    return date;
}



int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        try {
            stringstream ss(command);
            string operation_code;
            ss >> operation_code;
            if (operation_code == "Add") {
                string date, event;
                ss >> date;
                ss >> event;
                db.AddEvent(ParseDate(date), event);
            } else {
                if (operation_code == "Del") {
                    string date, event;
                    ss >> date;
                   // Date q = ParseDate(date);
                    if (ss >> event) {
                        if (db.DeleteEvent(ParseDate(date), event)) {
                            cout << "Deleted successfully" << endl;
                        } else {
                            cout << "Event not found" << endl;
                        }
                    } else {
                        int k = db.DeleteDate(ParseDate(date));
                        cout << "Deleted " <<
                        k << " events" << endl;
                    }

                } else if (operation_code == "Find") {
                    string date;
                    ss >> date;
                    db.Find(ParseDate(date));
                } else if (operation_code == "Print") {
                    db.Print();
                } else if (operation_code == "") {
                } else {
                    cout << "Unknown command: " << operation_code << endl;
                }
            }
        } catch (exception& ex) {
            cout << ex.what() << endl;
        }

    }
    return 0;
}
