#include <iostream>
using namespace std;

int Factorial (int a) {
    if (a < 0) {
        return 1;
    } else {
        while (a != 0) {
            a *= a;
            --a;
        }
        return a;
    }
}
int main() {
    cout << Factorial(10);
    return 0;
}