#include <iostream>
using namespace std;

int Factorial (int a) {
    int k = 1;
    if (a < 0) {
        return 1;
    } else {
        while (a != 0) {
            k *= a;
            --a;
        }
        return k;
    }
}

//int Factorial (int a) {
//    if (a <= 1) {
//        return 1;
//    } else {
//        return x * Factorial(a - 1);
//    }
//}

int main() {
    int x;
    cin >> x;
    cout << Factorial(x);
    return 0;
}