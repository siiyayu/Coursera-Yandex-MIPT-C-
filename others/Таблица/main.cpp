#include "test_runner.h"

using namespace std;

//template<typename Iterator>
//struct IteratorRange {
//    Iterator first, last;
//    Iterator begin() const {
//        return first;
//    }
//    Iterator end() const {
//        return last;
//    }
//};
//
//template<typename T>
//IteratorRange<typename vector<T>::iterator>> Head(const vector<T>& v, size_t top) {
//    return {v.begin(), v.begin() + min(v.size(), top)};
//}

template <typename T>
class Table {
public:
    Table(const size_t& rows, const size_t& columns) {
        Resize(rows, columns);
    }

    vector<T>& operator[](const int index) {
        return data[index];
    }
    const vector<T>& operator[](const int index) const {
        return data[index];
    }
    void Resize(size_t rows, size_t columns) {
        data.resize(rows);
        for (auto& item : data) {
            item.resize(columns);
        }
    }
    pair<size_t, size_t> Size() const {
        return {data.size(), data.empty() ? 0 : data[0].size()};
    }
private:
    vector<vector<T>> data;
};
void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}
