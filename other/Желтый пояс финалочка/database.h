#pragma once
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include "date.h"
#include <algorithm>
//#include <functional>

using namespace std;

ostream& operator<<(ostream& os, const pair<Date, vector<string>> item);

ostream& operator<<(ostream& os, const pair<Date, string> item);

class Database {
public:
    void Add(const Date& date, const string& event);

    template <class Predicate>
    int RemoveIf(Predicate pred) {

        int deleted_count = 0;
        for (auto it = date_to_events.begin(); it != date_to_events.end();) {
            auto delete_it = stable_partition(it->second.begin(), it->second.end(), [it, pred](const string &s) {
                return pred(it->first, s);
            });
            if (delete_it == it->second.end()) {
                deleted_count += date_to_events[it->first].size();
                auto temp = it;
                ++it;
                date_to_events.erase(temp->first);
                date_to_events_set.erase(temp->first);
            } else if (delete_it != it->second.begin()) {
                deleted_count += delete_it - it->second.begin();
//                for (auto set_it = it->second.begin(); set_it != delete_it;) {
//                    remove_if(date_to_events_set[it->first].begin(), date_to_events_set[it->first].end(), []);
//                }
                date_to_events_set[it->first].clear();
                date_to_events_set[it->first].insert(delete_it, it->second.end());
                date_to_events[it->first].erase(it->second.begin(), delete_it);
                it++;
            } else {
                ++it;
            }

        }
        return deleted_count;
    }
//        int deleted_count;
//        for (const auto& item : date_to_events) {
//            const Date& date = item.first;
//            auto it = stable_partition(item.second.begin(), item.second.end(),
//                                       [date, pred] (const string& s) {
//                                           return pred(date, s);
//                                       });
//            if (it == item.second.end()) {
//                deleted_count += date_to_events[date].size();
//                date_to_events.erase(date);
//            } else {
//                deleted_count += it - item.second.begin();
//                date_to_events[date].erase(item.second.begin(), it);
//            }
//        }
//        return deleted_count;


    template<class Predicate>
    vector<pair<Date, string>> FindIf(Predicate predicate) const {
        vector<pair<Date, string>> revealedPair;
        auto it_storage = date_to_events.begin();
//        cout << "First===========\n";
        while (it_storage != date_to_events.end()) {
//            cout << "Second==============\n";
            auto it_events = it_storage->second.begin();
            while (it_events != it_storage->second.end()) {
//                cout << "Third==============\n";
                it_events = find_if(it_events, it_storage->second.end(),
                                    [&](const string str) { return predicate(it_storage->first, str); });
                if (it_events != it_storage->second.end()) {
                    revealedPair.emplace_back(it_storage->first, *it_events);
                    ++it_events;
                };
            }
            ++it_storage;
        }
//        cout << "In metod FindIf. Vector size is: " << revealedPair.size() << endl;

        return revealedPair;
    };

//    template <class Predicate>
//    map<Date, vector<string>> FindIf(Predicate pred) const {
//        map<Date, vector<string>> result;
////        vector<string> test;
//        for (const auto& item : date_to_events) {
//            for (const auto& event : item.second) {
//                if (pred(item.first, event)) {
//                    result[item.first].emplace_back(event);
////                    test.emplace_back(event);
//                }
//            }
//        }
////        cout << result.size();
//        return result;
//    }

    void Print(ostream& os) const;

    pair<Date, string> Last(const Date& date) const;

private:
    map<Date, vector<string>> date_to_events;
    map<Date, set<string>> date_to_events_set;
};