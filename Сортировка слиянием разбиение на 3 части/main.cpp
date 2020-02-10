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
    auto it_first_part = elements.begin() + length/3;
    auto it_second_part = elements.begin() + 2*length/3;
    MergeSort(elements.begin(), it_first_part);
    MergeSort(it_first_part, it_second_part);
    MergeSort(it_second_part, elements.end());
    vector<typename RandomIt::value_type> temp; //  создание вектора,
    merge(elements.begin(), it_first_part, it_first_part, it_second_part, back_inserter(temp));
    merge(temp.begin(), temp.end(), it_second_part, elements.end(), range_begin);
//    merge(elements_pt1.begin(), elements_pt1.end(), elements_pt2.begin(), elements_pt2.end(), range_begin);
//    copy(elements_pt1.begin(), elements_pt1.end(), range_begin);
//    copy(elements_pt2.begin(), elements_pt2.end(), range_begin + length/2);
}

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}



