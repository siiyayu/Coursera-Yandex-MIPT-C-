#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith( RandomIt range_begin, RandomIt range_end, char prefix) {
    auto l = lower_bound(range_begin, range_end, prefix, [] (const string& item, const char val) {
        return item[0] < val;
    });
    auto r = upper_bound(range_begin, range_end, prefix, [] (const char val, const string& item) {
        return val < item[0];
    });
    return make_pair(l, r);
}

int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}

