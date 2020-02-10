#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main() {
    int q;
    cin >> q;
    map <string, vector <string>> bus_to_stops;
    vector <string> bus_map;
    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            bus_map.push_back(bus);
            for (int k = 0; k < stop_count; ++k) {
                string stop;
                cin >> stop;
                bus_to_stops[bus].push_back(stop);
            }
        } else
            if (operation_code == "BUSES_FOR_STOP") {
                string stop;
                cin >> stop;
                int k = 0;
                for (const string& n : bus_map) {
                    for (const string& m : bus_to_stops[n]) {
                        if (m == stop) {
                            ++k;
                            cout << n << " ";
                            break;
                        }
                    }
                }
                if (k == 0) {
                    cout << "No stop";
                }
                cout << endl;
            } else
                if (operation_code == "STOPS_FOR_BUS") {
                    string bus;
                    cin >> bus;
                    int k;
                    if (bus_to_stops.count(bus) == 0) {
                        cout << "No bus" << endl;
                    } else {
                        for (const string& stop : bus_to_stops[bus]) {
                            k = 0;
                            cout << "Stop " << stop << ": ";
                            for (const string& item : bus_map) {
                                if (item != bus) {
                                    for (const string& stop1: bus_to_stops[item]) {
                                        if (stop1 == stop) {
                                            cout << item << " ";
                                            ++k;
                                        }
                                    }
                                }
                            }
                            if (k == 0) {
                                cout << "no interchange";
                            }
                            cout << endl;
                        }
                    }
                } else
                    if (operation_code == "ALL_BUSES") {
                        if (bus_to_stops.size() == 0) {
                            cout << "No buses" << endl;
                        } else {
                            for (const auto& item : bus_to_stops) {
                                cout << "Bus " << item.first << ": ";
                                for (const string& stop : item.second) {
                                    cout << stop << " ";
                                }
                                cout << endl;
                            }
                        }
                    }
    }
    return 0;
}