#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 1, 4, 6, 2, 3};
    set<int> s(v.begin(), v.end());
    s.insert(s.begin(), 10);
    for (auto item : s) {
        cout << item << " ";
    }

    return 0;
}