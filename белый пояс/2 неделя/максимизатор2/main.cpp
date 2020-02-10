#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void UpdateIfGreater (const int first, int& second) {
    if (first > second) {
        second = first;
    }
}

void MoveStrings (vector <string>& source, vector <string>& destination) {
    for (auto a : source) {
        destination.push_back(a);
    }
    source.clear();
}

vector<int> Reversed (const vector<int>& v) {
    vector <int> x;
    x = v;
    for (int i = 0; i < x.size()/2; ++i) {
        int temp = x[i];
        x[i] = x[x.size() - 1 - i];
        x[x.size() - 1 - i] = temp;
    }
    return x;
}


int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reversed(numbers);
    for (auto a : numbers) {
        cout << a << ' ';
    }
    return 0;
}