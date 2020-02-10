#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> A(n);
    for (int& item : A) {
        cin >> item;
    }
    sort(A.begin(), A.end(), [](int x, int y) {
            return abs(x) < abs(y); //Binary function that accepts two elements in the range as arguments,
            // and returns a value convertible to bool. The value returned indicates whether the element
            // passed as first argument is considered to go before the second in the specific strict weak
            // ordering it defines.
    });
    for (int& item : A) {
        cout << item << " ";
    }
    return 0;
}