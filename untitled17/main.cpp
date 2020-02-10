#include <iostream>
using  namespace std;

int main() {
    int x = 5;
    int& y = x;
    cout << y;
    //y = 4;
    //cout << x;
    return 0;
}