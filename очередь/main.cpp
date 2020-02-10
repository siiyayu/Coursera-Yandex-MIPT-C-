#include <iostream>
using namespace std;
#include <vector>

int main() {
    int n, i, sum;
    cin >> n;
    vector <int> queue(n, 0);
    for (int k = 1; k <= n; ++k) {
        cin >> s;
        if (s == "WORRY") {
            cin >> i;
            queue[i] = 1;
        }
        if (s == "QUIET") {
            cin >> i;
            queue[i] = 0;
        }
        if (s == "COME") {
            cin >> i;
            queue.resize(queue.size() + i);
        }
        if (s == "WORRY_COUNT") {
            for (int a : queue) {
                sum += a;
            }
            cout << sum << endl;
        }

    }
    return 0;
}