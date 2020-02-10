#include <iostream>
#include <vector>
#include "profile.h"

using namespace std;

int main() {
    LOG_DURATION("Insert in vector")
    vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.insert(v.begin(), i);
    }
    return 0;
}