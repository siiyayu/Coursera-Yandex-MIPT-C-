#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        q.push_back(s);
    }
    vector<string> GetSortedStrings() {
        vector <string> m = q;
        sort(begin(m), end(m));
        return m;
    }
private:
    vector <string> q;
};

void print_sorted_strings (SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    print_sorted_strings(strings);

    strings.AddString("second");
    print_sorted_strings(strings);

    return 0;
}
