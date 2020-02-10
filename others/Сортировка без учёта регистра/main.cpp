#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string str_to_low (const string& s) {
    string result;
    for ( const auto item : s) {
        result += tolower(item);
    }
    return result;
}


int main() {

    int n;
    cin >> n;
    vector<string> v(n);
    for (string& x : v) {
        cin >> x;
        if (n > 1000 || x.size() > 15) {
            return 0;
        }
    }
    sort (begin(v), end(v), [](const string& l, const string& r) {
       return str_to_low(l) < str_to_low(r);
    });

//    sort(begin(v), end(v),
//         [](string l, string r) {
//        for (int i = 0; i < l.size(); ++i) {
//            if (tolower(l[i]) < tolower(r[i])) {
//            return true;
//            }
//        }
//        return false;
//        }
//    );

    for (const string& x : v) {
        cout << x << " ";
    }

    return 0;
}