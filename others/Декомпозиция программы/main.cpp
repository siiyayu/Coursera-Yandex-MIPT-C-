#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    Query empty;
    q = empty;
    string operation_code;
    is >> operation_code;
    if (operation_code == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        for (int i = 0; i < stop_count; i++) {
            string stop;
            is >> stop;
            q.stops.push_back(stop);
        }
    } else if (operation_code == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (operation_code == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (operation_code == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}

struct BusesForStopResponse {
    bool success = true;
    string error_message;
    string out;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (!r.success) {
        os << r.error_message;
    } else {
        os << r.out;
    }
    return os;
}

struct StopsForBusResponse {
    bool success = true;
    string error_message;
    string out;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (!r.success) {
        os << r.error_message;
    } else {
        os << r.out;
    }
    return os;
}

struct AllBusesResponse {
    bool success = true;
    string error_message;
    string out;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (!r.success) {
        os << r.error_message;
    } else {
        os << r.out;
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        int stop_count = stops.size();
        buses_to_stops[bus] = stops;
        for (auto stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse result;
        if (stops_to_buses.count(stop) == 0) {
            result.success = false;
            result.error_message = "No stop";
        } else {
            for (const string& bus : stops_to_buses.at(stop)) {
                result.out += bus + " ";
            }
        }
        return result;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse result;
        if (buses_to_stops.count(bus) == 0) {
            result.success = false;
            result.error_message = "No bus";
        } else {
            for (const string& stop : buses_to_stops.at(bus)) {
                result.out += string("Stop") + " " + stop + ": ";
                if (stops_to_buses.at(stop).size() == 1) {
                    result.out += "no interchange";
                } else {
                    for (const string& other_bus : stops_to_buses.at(stop)) {
                        if (bus != other_bus) {
                            result.out += other_bus + " ";
                        }
                    }
                }
                result.out += "\n";
            }
        }
        return result;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse result;
        if (buses_to_stops.empty()) {
            result.success = false;
            result.error_message = "No buses";
        } else {
            for (const auto& bus_item : buses_to_stops) {
                result.out += string("Bus") + " " + bus_item.first + ":" + " ";
                for (const string& stop : bus_item.second) {
                    result.out += stop + " ";
                }
                result.out += "\n";
            }
        }
        return  result;
    }

private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }
    return 0;
}

