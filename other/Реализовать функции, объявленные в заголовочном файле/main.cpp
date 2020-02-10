#include <sum_reverse_sort.h>
#include <algorithm>

using namespace std;

int Sum(int x, int y) {
    return x + y;
}

string Reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}
void Sort(vector<int>& nums) {
    sort(nums.begin(),nums.end());
//    int tmp = 0;
//    auto lenD = nums.size();
//    for(int i = 0; i < lenD; i++) {
//        for(int j = lenD - 1; j >= i + 1; j--) {
//            if(nums[j] < nums[j - 1]) {
//                tmp = nums[j];
//                nums[j] = nums[j - 1];
//                nums[j - 1] = tmp;
//            }
//        }
//    }
}
