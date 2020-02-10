#include <iostream>
using namespace std;
#include <vector>

int main() {
    int n, i;
    int sum = 0;
    cin >> n;
    string s;
    vector <bool> queue;
    for (int k = 0; k < n; ++k) {
        sum = 0;
        cin >> s;
        if (s == "WORRY" || s == "QUIET") {
            cin >> i;
            queue[i] = (s == "WORRY");
        } else
        if (s == "COME") {
            cin >> i;
            queue.resize(queue.size() + i);
        } else
        if (s == "WORRY_COUNT") {
            for (int a : queue) {
                if (a == 1) {
                    sum += a;
                }
            }
            cout << sum << endl;
        }

    }
    return 0;
}