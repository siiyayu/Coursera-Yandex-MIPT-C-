#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith( RandomIt range_begin, RandomIt range_end, const string prefix) {
if (prefix == "") {
return {range_begin, range_begin};
}
auto r = equal_range(range_begin, range_end, prefix, [prefix] (const string& lhs, const string& rhs) {
string l = lhs;
string r = rhs;
int l_size = l.size();
int r_size = r.size();
if (l_size == 0 || r_size == 0) {
return true;
}
if (l_size < r_size) {
r.resize(prefix.size());
}
else if (r_size < l_size) {
l.resize(prefix.size());
}
return l < r;
});
return r;
}

int main() {
const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

const auto mo_result =
FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
for (auto it = mo_result.first; it != mo_result.second; ++it) {
cout << *it << " ";
}
cout << endl;

const auto mt_result =
FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
cout << (mt_result.first - begin(sorted_strings)) << " " <<
(mt_result.second - begin(sorted_strings)) << endl;

const auto na_result =
FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
cout << (na_result.first - begin(sorted_strings)) << " " <<
(na_result.second - begin(sorted_strings)) << endl;

return 0;
}
