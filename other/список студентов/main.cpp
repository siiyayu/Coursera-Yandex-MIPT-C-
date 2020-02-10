#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    string date;
};

int main() {
    int n;
    vector <Student> students;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string first_name, last_name, day, month, year;
        cin >> first_name >> last_name >> day >> month >> year;
        students.push_back(Student{first_name + " " + last_name,
                                   day + "." + month + "." + year});
    }
    int m;
    cin >> m;
    string operation_code;
    int number;
    for (int i = 0; i < m; ++i) {
        cin >> operation_code >> number;
        --number;
        if (operation_code == "name" && number >= 0 && number < n) {
            cout << students[number].name << endl;
        } else if (operation_code == "date" && number >= 0 && number < n) {
            cout << students[number].date << endl;
        } else {
            cout << "bad request" << endl;
        }
    }


    return 0;
}