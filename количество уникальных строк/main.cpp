#include <iostream>
#include <set>
using namespace std;

int main() {
    set <string> words;
    string word;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        words.insert(word);
    }
    cout << words.size();
    return 0;
}