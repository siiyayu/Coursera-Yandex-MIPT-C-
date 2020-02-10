#include <iostream>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;
    string operation_code;
    map <string, string> country_to_capital;
    for (int i = 0; i < q; ++i) {
        int size = country_to_capital.size();
        cin >> operation_code;
        if (operation_code == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (country_to_capital.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else {
                string old_capital = country_to_capital[country];
                if (old_capital == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else
                    if (old_capital != new_capital) {
                        cout << "Country " << country << " has changed its capital from " << old_capital << " to "
                        << new_capital << endl;
                    }}
            country_to_capital[country] = new_capital;
        } else
        if (operation_code == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (country_to_capital.count(old_country_name) == 0 || old_country_name == new_country_name ||
            country_to_capital.count(new_country_name) != 0) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital " << country_to_capital[old_country_name] <<
                " has been renamed to " << new_country_name << endl;
                country_to_capital[new_country_name] = country_to_capital[old_country_name];
                country_to_capital.erase(old_country_name);
            }
        } else
        if (operation_code == "ABOUT") {
            string country;
            cin >> country;
            if (country_to_capital.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
            }
        } else
        if (operation_code == "DUMP") {
            if (country_to_capital.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto& item : country_to_capital) {
                    cout << item.first << "/" << item.second << " ";
                }
            }

        }
    }
    return 0;
}