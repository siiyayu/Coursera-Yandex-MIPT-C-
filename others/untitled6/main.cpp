#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;
    map <string, set <string>> synonims;
    string word1, word2;
    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;
        if (operation_code == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            synonims[word1].insert(word2);
            synonims[word2].insert(word1);
        } else if (operation_code == "COUNT") {
            cin >> word1;
            cout << synonims[word1].size() << endl;
        } else if (operation_code == "CHECK") {
            cin >> word1 >> word2;
            if (synonims[word1].count(word2) != 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}