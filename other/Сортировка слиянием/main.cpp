 #include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    int length = range_end - range_begin;
    if (length < 2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end); //  создание вектора,
    // содержащего элементы диапазона
//    vector<typename RandomIt::value_type> elements_pt1(length/2);
//    vector<typename RandomIt::value_type> elements_pt2(length/2);
//    copy(range_begin, range_begin + length/2, elements_pt1.begin());
//    copy(range_begin + length/2, range_end, elements_pt2.begin());
//    for (int i = 0; i < length / 2; i++) {
//        elements_pt1.push_back(elements[i]);
//    }
//    for (int i = length / 2; i != length; i++) {
//        elements_pt2.push_back(elements[i]);
////    }
    auto it_middle = elements.begin() + length/2;
    MergeSort(elements.begin(), it_middle);
    MergeSort(it_middle, elements.end());
    merge(elements.begin(), it_middle, it_middle, elements.end(), range_begin);

//    merge(elements_pt1.begin(), elements_pt1.end(), elements_pt2.begin(), elements_pt2.end(), range_begin);
//    copy(elements_pt1.begin(), elements_pt1.end(), range_begin);
//    copy(elements_pt2.begin(), elements_pt2.end(), range_begin + length/2);
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}


