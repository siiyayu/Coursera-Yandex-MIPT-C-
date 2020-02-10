#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    cin >> x;
    vector <int> a;
    while (x != 0 && x != 1) {
        a.insert(a.begin(), x % 2);
        x = x/2;
    }
        a.insert(a.begin(), x);
    for (auto i : a) {
        cout << i;
    }
    return 0;
}