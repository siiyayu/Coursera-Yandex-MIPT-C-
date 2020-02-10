#include <iostream>
#include <string>
#include <map>

using namespace std;

template <typename Key, typename Value>
const Value& GetRefStrict(const map<Key, Value>& m, const Key& key) {
    if (m.count(key) == 0) {
        throw runtime_error("not found");
    }
    return m.at(key);
}

int main() {
    string test;
    test += string("jjj") + string(" ");
    test += "\n";
    test += "fff";
    cout << test;
    return 0;
}
