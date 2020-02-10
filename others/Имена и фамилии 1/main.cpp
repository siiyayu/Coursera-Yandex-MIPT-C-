#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
    string name;
    for (const auto& item : names) {
        if (item.first <= year) {
            name = item.second;
        } else {
            break;
        }
    }
    return name;
}
vector <string> FindNamesByYear(const map<int, string>& names, int year) {
    vector <string> result;
    string name;
    for (const auto& item : names) {
        if (item.first <= year) {
             result.insert(result.begin(), item.second);
        } else {
            break;
        }
    }
    return result;
}

string PrintNames(vector <string> v) {
    string result;
    vector <string> v_new;
    v_new.push_back(v[0]);
    for (int k = 1; k < v.size(); k++) {
        if (v[k - 1] != v[k]) {
            v_new.push_back(v[k]);
        }
    }
    for (int i = 0; i < v_new.size(); ++i) {
        if (i == 0) {
            result += v_new[i];
        } else if (i == 1) {
            result += " (" + v_new[i];
        } else if (i > 1) {
            result += ", " + v_new[i];
        }
        if (i == v_new.size() - 1 && i != 0) {
            result += ")";
        }
    }
    return result;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else {
            return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) {
        string result;
        vector<string> FirstNamesResult;
        vector<string> LastNamesResult;
        FirstNamesResult = FindNamesByYear(first_names, year);
        LastNamesResult = FindNamesByYear(last_names, year);
        if (FirstNamesResult.empty() && LastNamesResult.empty()) {
            return "Incognito";
        } else if (FirstNamesResult.empty()) {
            return PrintNames(LastNamesResult) + " with unknown first name";
        } else if (LastNamesResult.empty()) {
            return PrintNames(FirstNamesResult) + " with unknown last name";
        } else {
            return PrintNames(FirstNamesResult) + " " + PrintNames(LastNamesResult);
        }
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
