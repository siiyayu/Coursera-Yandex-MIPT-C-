#include <iostream>
#include <map>
using namespace std;

map <char, int> BuildCharCounters (const string& s) {
    map <char, int> m;
    for (const char& item : s) {
        ++m[item];
    }
    return m;
}


int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string a, b;
        cin >> a >> b;
        if (BuildCharCounters(a) == BuildCharCounters(b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}