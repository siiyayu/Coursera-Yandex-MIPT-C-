#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool IsPalindrom(string s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector <string> PalindromFilter (vector <string> words, int minLength) {
    vector <string> result;
    for (auto a : words) {
        if (IsPalindrom(a) && a.size() >= minLength) {
            result.push_back(a);
        }
    }
    return result;
}

int main() {
    return 0;
}