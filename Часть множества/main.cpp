#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){

    auto b = find_if(begin(elements), end(elements),
            [border](T n) {return n > border;});
    return {b, end(elements)};

}

//
//template <typename T>
//vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
//    vector <T> result;
//    auto border_it = find(elements.begin(), elements.end(), border);
//    if (border_it != elements.end()) {
//        border_it++;
//    }
//    for (auto it = border_it; it != elements.end(); ++it) {
//        result.push_back(*it);
//    }
//    return result;
//}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "C";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}
