#include <iostream>
using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
    sort(begin(elements), end(elements));
    elements.erase(
            unique(begin(elements), end(elements)),
            elements.end());
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}