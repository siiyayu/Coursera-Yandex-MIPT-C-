#include <iostream>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector <vector<string>> days_affairs(31); // 31 векторов-строк (дел) в месяце
    vector <int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int month_count = days_in_month.size();
    for (int i = 0; i < q; ++i) {
        int day;
        int month = 0;
        string operation_code, affair;
        cin >> operation_code;
        if (operation_code == "ADD") {
            cin >> day;
            cin >> affair;
            days_affairs[day - 1].push_back(affair);
        } else
        if (operation_code == "NEXT") {
            const int old_days_in_month = days_in_month[month];
            month = (month + 1)%month_count;
            const int new_days_in_month = days_in_month[month];
            if (new_days_in_month  < old_days_in_month ) {
                vector <string>& last_day_affairs = days_affairs[new_days_in_month - 1];
                for (int day = new_days_in_month; day < old_days_in_month; ++day) {
                    last_day_affairs.insert(end(last_day_affairs),
                            begin(days_affairs[day]),
                            end((days_affairs[day])));
            }

        }
            days_affairs.resize(new_days_in_month);
        } else
        if (operation_code == "DUMP") {
            cin >> day;
            cout << days_affairs[day - 1].size();
                for (const string &item: days_affairs[day - 1]) {
                    cout << " " << item;
                }
            cout << endl;
        }
        }
    return 0;
}