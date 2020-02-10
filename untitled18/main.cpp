#include <iostream>
#include <array>
#include <string_view>


using namespace std;

int main() {
    string_view sv;
    {
        string s = "abcd";
        sv = s;
    }

    for (auto s : sv) {
        cout << s << " ";
    }
    return 0;
}