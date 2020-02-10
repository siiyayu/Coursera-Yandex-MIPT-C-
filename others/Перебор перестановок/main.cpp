#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void PrintVector(const vector<int>& v) {
    cout << v[0];
    for (int i = 1; i < v.size(); i++) {
        cout << " " << v[i];
    }
    cout << endl;
}

void PrintPermutations(int number) {
    vector<int> numbers;
    while (number != 0) {
        numbers.push_back(number--);
    }
    do {
        PrintVector(numbers);
    } while (prev_permutation(numbers.begin(), numbers.end()));


}

int main() {
    int number;
    while (cin >> number) {
        PrintPermutations(number);
    }
    return 0;
}