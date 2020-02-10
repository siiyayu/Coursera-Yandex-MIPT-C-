#include <iostream>
#include <string>
#include <map>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& key) {
//    auto temp = m.find(key);
//    if (temp == m.end()) {
//        throw runtime_error("not found");
//    }
//    return temp;
    if (m.count(key) == 0) {
        throw runtime_error("not found");
    }
    Value& result = m.at(key);
    return result;
}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl;
    return 0;
}