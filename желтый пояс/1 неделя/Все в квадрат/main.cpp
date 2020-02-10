#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;

template <typename Key, typename Value>
pair<Key, Value> operator *(const pair<Key, Value>& lhs, const pair<Key, Value>& rhs);

template <typename Key, typename Value>
map<Key, Value> operator *(const map<Key, Value> &lhs, const map<Key, Value>& rhs);

template <typename T>
vector<T> operator * (const vector<T>& lhs,const  vector<T>& rhs);

template <typename T>
auto Sqr(const T& t);

template <typename Key, typename Value>
pair<Key, Value> operator *(const pair<Key, Value>& lhs, const pair<Key, Value>& rhs) {
    pair <Key, Value> result;
    result.first = lhs.first * rhs.first;
    result.second = lhs.second * rhs.second;
    return result;
}

template <typename Key, typename Value>
map<Key, Value> operator *(const map<Key, Value> &lhs, const map<Key, Value>& rhs) {
    map<Key, Value> result;
    for (auto item : lhs){
        result[item.first] = item.second * item.second;
    }
    return result;
}

template <typename T>
vector<T> operator * (const vector<T>& lhs,const vector<T>& rhs) {
    vector <T> result;
    for (int i = 0; i < lhs.size(); i++) {
        auto temp = lhs[i] * rhs[i];
        result.push_back(temp);
    }
    return result;
}

template <typename T>
auto Sqr(const T& t) {
    return t * t;
}

int main() {
    vector<double> v = {1.6, 6.7, 3};
    cout << "vector:";
    for (double x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}