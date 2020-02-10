#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

#define mmi(x) { \
make_move_iterator(x) \
}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
// Напишите реализацию функции,
// не копируя сортируемые элементы
    if (range_end - range_begin < 2) {
        return;
    }
    vector<typename RandomIt::value_type> v(make_move_iterator(range_begin), make_move_iterator(range_end));
    auto it1 = v.begin() + v.size()/3;
    auto it2 = it1 + v.size()/3;
    MergeSort(v.begin(), it1);
    MergeSort(it1, it2);
    MergeSort(it2, v.end());
    vector<typename RandomIt::value_type> temp;
//    move(v.begin(), it1, back_inserter(temp));
//    move(it1, it2, back_inserter(temp));
//    move(it2, v.end(), back_inserter(temp));
//    move(temp.begin(), temp.end(), range_begin);

    merge(make_move_iterator(v.begin()), make_move_iterator(it1), make_move_iterator(it1), make_move_iterator(it2), back_inserter(temp));
    merge(make_move_iterator(temp.begin()), make_move_iterator(temp.end()), make_move_iterator(it2), make_move_iterator(v.end()), range_begin);
}

class StringNonCopyable : public string {
public:
    using string::string;
    StringNonCopyable(string&& other) : string(move(other)) {}
    StringNonCopyable(const StringNonCopyable&) = delete;
    StringNonCopyable(StringNonCopyable&&) = default;
    StringNonCopyable& operator=(const StringNonCopyable&) = delete;
    StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
    vector<StringNonCopyable> strings;
    static const int SIZE = 10;
    for (int i = 0; i < SIZE; ++i) {
        strings.push_back(StringNonCopyable(to_string(i)));
    }
    MergeSort(strings.begin(), strings.end());
    for (int i = 0; i < SIZE; ++i) {
        ASSERT_EQUAL(strings[i], to_string(i));
    }
}



//struct NoncopyableInt {
//    int value;
//
//
//    NoncopyableInt(const NoncopyableInt&) = delete;
//    NoncopyableInt& operator=(const NoncopyableInt&) = delete;
//    NoncopyableInt(int&&);
//
//    NoncopyableInt(NoncopyableInt&&) = default;
//    NoncopyableInt& operator=(NoncopyableInt&&) = default;
//};
//
//bool operator < (const NoncopyableInt& lhs, const NoncopyableInt& rhs) {
//    return lhs.value < rhs.value;
//}


//void TestIntVector() {
//    vector<NoncopyableInt> numbers;
//    numbers.push_back({6});
//    numbers.push_back({1});
//    numbers.push_back({3});
//    numbers.push_back({9});
//    numbers.push_back({1});
//    numbers.push_back({9});
//    numbers.push_back({8});
//    numbers.push_back({12});
//    numbers.push_back({1});
//    MergeSort(begin(numbers), end(numbers));
//    ASSERT(is_sorted(begin(numbers), end(numbers)));
//}


//bool operator == (const NoncopyableInt& lhs, const NoncopyableInt& rhs) {
//    return lhs.value == rhs.value;
//}
//
//ostream& operator << (ostream& os, const NoncopyableInt& v) {
//    return os << v.value;
//}
//
//void TestAvoidsCopying() {
//    vector<NoncopyableInt> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
//    ASSERT(is_sorted(begin(numbers), end(numbers)));
//}

void TestIntVector() {
    vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
    MergeSort(begin(numbers), end(numbers));
    ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
TestRunner tr;
RUN_TEST(tr, TestIntVector);
RUN_TEST(tr, TestNoCopy);
return 0;
}
